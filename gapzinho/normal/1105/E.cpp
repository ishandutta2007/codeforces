#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1005;
const ll mod = 1e9+7;

map<string, int> dic;
int def[50];
int f = 0;
int n, m;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<bitset<40>> vb;
vb g;
struct Maxclique {
	double limit=0.025, pk=0;
	struct Vertex { int i, d=0; };
	typedef vector<Vertex> vv;
	vb e;
	vv V;
	vector<vi> C;
	vi qmax, q, S, old;
	void init(vv& r) {
		for (auto& v : r) v.d = 0;
		for (auto& v : r) for (auto j : r) v.d += e[v.i][j.i];
		sort(all(r), [](auto a, auto b) { return a.d > b.d; });
		int mxD = r[0].d;
		rep(i,0,sz(r)) r[i].d = min(i, mxD) + 1;
	}
	void expand(vv& R, int lev = 1) {
		S[lev] += S[lev - 1] - old[lev];
		old[lev] = S[lev - 1];
		while (sz(R)) {
			if (sz(q) + R.back().d <= sz(qmax)) return;
			q.push_back(R.back().i);
			vv T;
			for(auto v:R) if (e[R.back().i][v.i]) T.push_back({v.i});
			if (sz(T)) {
				if (S[lev]++ / ++pk < limit) init(T);
				int j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1);
				C[1].clear(), C[2].clear();
				for (auto v : T) {
					int k = 1;
					auto f = [&](int i) { return e[v.i][i]; };
					while (any_of(all(C[k]), f)) k++;
					if (k > mxk) mxk = k, C[mxk + 1].clear();
					if (k < mnk) T[j++].i = v.i;
					C[k].push_back(v.i);
				}
				if (j > 0) T[j - 1].d = 0;
				rep(k,mnk,mxk + 1) for (int i : C[k])
					T[j].i = i, T[j++].d = k;
				expand(T, lev + 1);
			} else if (sz(q) > sz(qmax)) qmax = q;
			q.pop_back(), R.pop_back();
		}
	}
	vi maxClique() { init(V), expand(V); return qmax; }
	Maxclique(vb conn) : e(conn), C(sz(e)+1), S(sz(C)), old(S) {
		rep(i,0,sz(e)) V.push_back({i});
	}
};


void endCycle() {
    for(int i = 0; i < n; i++) {
        if(!def[i]) continue;
        def[i] = 0;
        for(int j = i+1; j < n; j++) {
            if(def[j]) {
                // cout << "zerando " << i << ' ' << j << endl;
                g[i][j] = 0;
                g[j][i] = 0;
            }
        }
    }
}


int main() {
    cin >> m >> n;
    g.resize(n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j] = (i == j) ? 0 : 1;
    while(m--) {
        int t;
        cin >> t;
        if(t == 1) {
            endCycle();
        } else {
            string s;
            cin >> s;
            if(!dic.count(s)) dic[s] = f++;
            def[dic[s]] = 1;
            // cout << def[0] << ' ' << def[1] << ' ' << def[2] << endl; 
            // cout << dic[s] << " aa" << endl;
        }
    }
    endCycle();
    for(int i = 0; i < n; i++) {
        // cout << g[i] << endl;
    }
    Maxclique c(g);
    vi ans = c.maxClique();
    // for(auto x : ans) cout << x << endl;
    cout <<  ans.size() << endl;
}
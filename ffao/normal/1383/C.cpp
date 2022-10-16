#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority queue for lexic. smallest ans.
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
	while (!q.empty()) {
		int i = -q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(-x);
	}
	return ret;
}

int hase[20][20];
int hasce[20][20];
int fr[20];
int cost[2100000];
vector< vector<int> > g;
int tot;

void solve() {
    rep(i,0,20) rep(j,0,20) hase[i][j] = hasce[i][j] = 0;
    string s1, s2;
    
    tot = 0;

    int nL; cin >> nL;
    cin >> s1 >> s2;
    for (int i = 0; i < nL; i++) {
        if (s1[i] != s2[i]) hase[s1[i]-'a'][s2[i]-'a']=1;
    }

    g = vector< vi >(20, vector<int>());
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) if (i != j && hase[i][j]) g[i].push_back(j);
    }

    scc(g, [&](vi& comp) {
        int hm = comp.size();

        int ans = 1000000000;

        for (int i = 0; i < hm; i++) {
            fr[i] = 0;
            for (int j = 0; j < hm; j++) if (j != i && hase[comp[j]][comp[i]]) {
                fr[i] |= (1<<j);
            }
        }

        for (int i = 0; i < (1<<hm); i++) cost[i] = 1000000000;
        cost[(1<<hm)-1] = 0;

        for (int bm = (1<<hm)-1; bm > 0; bm--) {
            int tmp = bm;
            while (tmp) {
                int bt = __builtin_ctz(tmp&-tmp);
                tmp ^= (tmp&-tmp);
                
                cost[bm ^ (1<<bt)] = min(cost[bm ^ (1<<bt)], cost[bm] + ((fr[bt] & bm) != 0));
            }
        }

        tot += (hm-1) + cost[0];

        // for (int bm = 0; bm < (1<<hm); bm++) {
        //     int val = (hm-1) + __builtin_popcount(bm);
        //     if (ans <= val) continue;

        //     vector< vi > ing(hm, vi());
        //     for (int i= 0; i < hm; i++) {
        //         for (int j = 0; j < hm; j++) if (!( (1<<j) & bm)) {
        //             if (hase[comp[i]][comp[j]]) ing[i].push_back(j);
        //         }
        //     }

        //     vi xx = topoSort(ing);

        //     if (xx.size() == hm) {
        //         // cout << "from " << bm << " ans = " << val << " hm = " << hm << '\n';
        //         ans = min(ans, val);
        //     }
        // }
        // tot += ans;
    });

    // cout << "tot " << tot << endl;
    for (int cc = ncomps-1; cc >= 0; cc--) {
        vi outs;
        for (int i = 0; i < 20; i++) if (comp[i] == cc) {
            for (int j = 0; j < 20; j++) if (comp[j] != comp[i] && hase[i][j]) {
                hasce[cc][comp[j]]=1;
            }
        }

        int maxo = -1;
        for (int i = 0; i < 20; i++) if (i != cc && hasce[cc][i]) {
            maxo = max(maxo, i);
        }

        if (maxo != -1) {
            tot++;
            for (int i = 0; i < 20; i++) if (i != cc && i != maxo && hasce[cc][i]) {
                hasce[maxo][i] = 1;
            }
        }
    }

    cout << tot << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        solve();
    }

    return 0;
}
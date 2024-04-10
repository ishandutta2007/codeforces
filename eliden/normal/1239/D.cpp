#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    rep(test,0,tests) {
        int n, m;
        cin >> n >> m;
        vector<vi> g(n);
        rep(i,0,m) {
            int a, b;
            cin >> a >> b;
            if(a==b) continue;
            --a;
            --b;
            g[a].push_back(b);
        }
        scc(g, [&](vi &v) {});
        vector<int> parta, partb;
        rep(i,0,n) {
            if(comp[i]==0) parta.push_back(i);
            else partb.push_back(i);
        }
        if(sz(parta)==n) cout<<"No\n";
        else {
            cout<<"Yes\n";
            cout<<sz(parta)<<" "<<sz(partb)<<"\n";
            for(int x:parta) cout<<x+1<<" ";
            cout<<"\n";
            for(int x:partb) cout<<x+1<<" ";
            cout<<"\n";
        }
    }
}
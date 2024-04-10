#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10;
int t, n, m;
vector<pi> V[nax];
bool vis[nax];
bool cyc = 0;

void dfs(int x, int last) {
    vis[x] = 1;
    for(auto nbh : V[x]) {
        if(!vis[nbh.ST]) {
            dfs(nbh.ST, nbh.ND);
        } else if(nbh.ND != last && nbh.ST != x) {
            cyc = 1;
        }
    }
}


int main() {_
	cin >> t;
	while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            V[i].clear();
            vis[i] = 0;
        }
        int ans = 0;
        for(int a,b,i = 1; i <= m; ++i) {
            cin >> a >> b;
            V[a].PB({b, i});
            V[b].PB({a, i});
            ans += (a != b);
        }
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                cyc = 0;
                dfs(i, -1);
                if(cyc) ans++;
            }
        }
        cout << ans << "\n";
	}
}
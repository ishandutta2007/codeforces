#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

const int nax = 300 * 1000 + 10;
int t,n,a,b,da,db;
int d[nax];
vi V[nax];
pi mx;

void dfs(int x, int p) {
    d[x] = d[p] + 1;
    mx = max(mx,{d[x], x});
    for(int nbh : V[x]) if(nbh != p) {
        dfs(nbh, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> da >> db;
        for(int i = 1; i <= n; ++i) {
            V[i].clear();
        }
        for(int u,v,i = 1; i < n; ++i) {
            cin >> u >> v;
            V[u].PB(v);
            V[v].PB(u);
        }
        mx = {-1, 0};
        dfs(a, 0);
        if(2 * da >= db || d[b] - d[a] <= da) {
            cout << "Alice\n";
            continue;
        }
        int v = mx.ND;
        mx = {-1, 0};
        dfs(v, 0);
        mx.ST--;
        if(2 * da >= min(mx.ST, db)) {
            cout << "Alice\n";
        } else cout << "Bob\n";
    }

}
#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, m, s;
vector<int> g[200010];
int chk[200010];
int p[200010];

void dfs(int x, int r) {
    for(auto i : g[x]) {
        if(i == s) continue;
        
        if(chk[i]) {
            if(chk[i] != chk[x]) {
                vector<int> ans[2];

                for(int v = i; v; v = p[v]) ans[0].eb(v);
                p[i] = x;
                for(int v = i; v; v = p[v]) ans[1].eb(v);

                reverse(all(ans[0]));
                reverse(all(ans[1]));

                cout << "Possible\n";
                cout << ans[0].size() << "\n";
                for(auto i : ans[0]) cout << i << " ";
                cout << "\n";
                cout << ans[1].size() << "\n";
                for(auto i : ans[1]) cout << i << " ";
                cout << "\n";

                exit(0);
            }

            continue;
        }
        
        chk[i] = r;
        p[i] = x;
        dfs(i, r);
    }
}

int main() {
    fast;

    cin >> n >> m >> s;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
    }

    for(auto i : g[s]) {
        if(chk[i]) {
            vector<int> ans[2];

            for(int v = i; v; v = p[v]) ans[0].eb(v);
            p[i] = s;
            for(int v = i; v; v = p[v]) ans[1].eb(v);

            reverse(all(ans[0]));
            reverse(all(ans[1]));

            cout << "Possible\n";
            cout << ans[0].size() << "\n";
            for(auto i : ans[0]) cout << i << " ";
            cout << "\n";
            cout << ans[1].size() << "\n";
            for(auto i : ans[1]) cout << i << " ";
            cout << "\n";
            return 0;
        }
        p[i] = s;
        chk[i] = i;
        dfs(i, i);
    }

    cout << "Impossible";
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 300300;
const ll mod = 998244353;

using namespace std;

int n;
int m;
int a;
int b;
int p[N];
int used[N];
bool fuck;
vector < int > v[N];

void dfs(int x, int p)
{
        if(used[x]){
                if(used[x] != p){
                        fuck = 1;
                }
                return;
        }
        used[x] = p;
        a += p == 1;
        b += p == 2;
        for(int y: v[x]){
                dfs(y, 3 - p);
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                used[i] = 0;
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        p[0] = 1;
        for(int i = 1; i <= n; i++){
                p[i] = p[i - 1] + p[i - 1];
                if(p[i] >= mod){
                        p[i] -= mod;
                }
        }
        int ans = 1;
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        a = b = 0;
                        fuck = false;
                        dfs(i, 1);
                        if(fuck){
                                cout << 0 << "\n";
                                return;
                        }
                        ans = 1ll * ans * (p[a] + p[b]) % mod;
                }
        }
        cout << ans << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}
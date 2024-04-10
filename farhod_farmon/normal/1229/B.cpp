#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
long long a[N];
vector < int > v[N];
vector < pair < long long, int > > g[N];

long long res;

void dfs(int x, int p)
{
        if(x != 1){
                long long cur;
                g[x].push_back({a[x], 1});
                for(auto f: g[p]){
                        cur = __gcd(a[x], f.fi);

                        if(cur == g[x].back().fi){
                                g[x].back().se += f.se;
                        } else{
                                g[x].push_back({cur, f.se});
                        }
                }
        }

        for(auto f: g[x]){
                res += (f.fi % mod) * f.se % mod;
                if(res >= mod){
                        res -= mod;
                }
        }

        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;

                v[x].push_back(y);
                v[y].push_back(x);
        }

        g[1].push_back({a[1], 1});

        dfs(1, 1);

        cout << res << "\n";
}
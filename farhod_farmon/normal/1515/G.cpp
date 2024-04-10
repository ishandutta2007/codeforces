#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
bool used[N];
vector < pair < int, int > > v[N], gv[N];
vector < int > ord;

void dfs(int x)
{
        used[x] = true;
        for(auto y: v[x]){
                if(!used[y.fi]){
                        dfs(y.fi);
                }
        }
        ord.push_back(x);
}

vector < int > comp;
bool us[N];

void dfs2(int x)
{
        used[x] = true;
        comp.push_back(x);
        for(auto y: gv[x]){
                if(!used[y.fi]){
                        dfs2(y.fi);
                }
        }
}

long long g;
long long res[N];
long long d[N];

void solve(int x)
{
        for(auto y: v[x]){
                if(!us[y.fi]){
                        continue;
                } else if(d[y.fi] != -1){
                        g = __gcd(g, abs(d[y.fi] - d[x] - y.se));
                } else{
                        d[y.fi] = d[x] + y.se;
                        solve(y.fi);
                }
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                gv[y].push_back({x, w});
        }

        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i);
                }
        }
        reverse(ord.begin(), ord.end());
        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }
        for(int x: ord){
                if(used[x]){
                        continue;
                }
                comp.clear();
                dfs2(x);

                for(int x: comp){
                        us[x] = true;
                        d[x] = -1;
                }

                g = 0;
                d[x] = 0;
                solve(x);

                for(int x: comp){
                        us[x] = false;
                        res[x] = g;
                }
        }

        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int x, s, t;
                cin >> x >> s >> t;
                if(s % __gcd((long long)t, res[x]) == 0){
                        cout << "YES" << "\n";
                } else{
                        cout << "NO" << "\n";
                }
        }
}
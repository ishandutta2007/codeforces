#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int ans[N];
vector < int > v[N];
vector < int > g[N];

void dfs(int x, int p)
{
        g[x] = p[g];
        int ng = __gcd(g[x][0], a[x]);
        for(int i = 1; i < g[x].size(); i++){
                g[x][i] = __gcd(g[x][i], a[x]);
        }
        if(ng != g[x][0]){
                g[x].push_back(g[x][0]);
                g[x][0] = ng;
        }
        for(int b: g[x]){
                ans[x] = max(ans[x], b);
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
}

void solve()
{
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
        g[0].push_back(0);
        dfs(1, 0);
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
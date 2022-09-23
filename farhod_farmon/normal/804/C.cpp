#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 600300;
const long long MX = 11;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int c[N];
bool used[N];
vector < int > v[N], g[N];

void dfs(int x, int p)
{
        for(int y: g[x]){
                used[c[y]] = true;
        }
        int col = 1;
        for(int y: g[x]){
                if(c[y]){
                        continue;
                }
                while(used[col] == true){
                        col++;
                }
                c[y] = col;
                used[col] = true;
        }
        for(int y: g[x]){
                used[c[y]] = false;
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
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int l;
                cin >> l;
                g[i].resize(l);
                for(int j = 0; j < l; j++){
                        cin >> g[i][j];
                }
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        dfs(1, -1);
        int ans = 0;
        for(int i = 1; i <= m; i++){
                if(!c[i]){
                        c[i] = 1;
                }
                ans = max(ans, c[i]);
        }
        cout << ans << endl;
        for(int i = 1; i <= m; i++){
                cout << c[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
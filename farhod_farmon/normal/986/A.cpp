#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 4 * N;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int k;
int s;
int a[N];
int d[N];
vector < int > v[N];
vector < int > g[N];

void bfs(int x)
{
        queue < int > q;
        for(int i = 1; i <= n; i++){
                if(a[i] == x){
                        d[i] = 0;
                        q.push(i);
                }
                else{
                        d[i] = 1e9;
                }
        }
        while(!q.empty()){
                x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[y] == 1e9){
                                d[y] = d[x] + 1;
                                q.push(y);
                        }
                }
        }
}

void solve()
{
        cin >> n >> m >> k >> s;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1; i <= k; i++){
                bfs(i);
                for(int j = 1; j <= n; j++){
                        g[j].push_back(d[j]);
                }
        }
        for(int i = 1; i <= n; i++){
                sort(g[i].begin(), g[i].end());
                int ans = 0;
                for(int j = 0; j < s; j++){
                        ans += g[i][j];
                }
                cout << ans << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
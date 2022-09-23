#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int tim;
int d[N];
int tin[N];
int fin[N];
bool mo[N];
bool used[N];
vector < pair < int, int > > v[N];

void dfs(int x, int p)
{
        used[x] = 1;
        fin[x] = tin[x] = ++tim;
        for(auto pp: v[x]){
                int y = pp.fi, h = pp.se;
                if(y == p){
                        continue;
                }
                if(used[y]){
                        fin[x] = min(fin[x], tin[y]);
                }
                else{
                        dfs(y, x);
                        fin[x] = min(fin[x], fin[y]);
                        if(fin[y] > tin[x]){
                                mo[h] = 1;
                        }
                }
        }
}

int bfs(int x)
{
        for(int i = 1; i <= n; i++){
                d[i] = 1e9;
        }
        queue < int > q;
        d[x] = 0;
        q.push(x);
        while(!q.empty()){
                x = q.front();
                q.pop();
                for(auto pp: v[x]){
                        int y = pp.fi, h = pp.se;
                        if(d[x] + mo[h] < d[y]){
                                d[y] = d[x] + mo[h];
                                q.push(y);
                        }
                }
        }
        x = 1;
        for(int i = 1; i <= n; i++){
                if(d[i] > d[x]){
                        x = i;
                }
        }
        return x;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back({y, i});
                v[y].push_back({x, i});
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i, -1);
                }
        }
        cout << d[bfs(bfs(1))] << "\n";
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
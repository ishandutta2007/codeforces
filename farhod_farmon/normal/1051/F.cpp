#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int tim;
int A[N];
int B[N];
int tin[N];
int tout[N];
int p[N][20];
long long dx[N];
long long dy[N];
long long dip[N];
long long ans[N];
vector < pair < int, int > > v1[N];
vector < pair < int, int > > v2[N];

int get(int x)
{
        return x == p[x][0] ? x : p[x][0] = get(p[x][0]);
}

void dfs(int x, int pe)
{
        tin[x] = ++tim;
        p[x][0] = pe;
        for(int i = 1; i < 20; i++){
                p[x][i] = p[p[x][i - 1]][i - 1];
        }
        for(auto y: v1[x]){
                if(y.fi == pe){
                        continue;
                }
                dip[y.fi] = dip[x] + y.se;
                dfs(y.fi, x);
        }
        tout[x] = ++tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        }
        if(isp(y, x)){
                return y;
        }
        for(int i = 19; i >= 0; i--){
                if(!isp(p[x][i], y)){
                        x = p[x][i];
                }
        }
        return p[x][0];
}

void djk(int x, long long *d)
{
        for(int i = 1; i < N; i++){
                d[i] = 1e18;
        }
        d[x] = 0;
        set < pair < long long, int > > s;
        s.insert({0, x});
        while(!s.empty()){
                x = s.begin()->se;
                s.erase(s.begin());
                for(auto y: v2[x]){
                        if(d[x] + y.se < d[y.fi]){
                                s.erase({d[y.fi], y.fi});
                                d[y.fi] = d[x] + y.se;
                                s.insert({d[y.fi], y.fi});
                        }
                }
        }
}

void solve()
{
        cin >> n >> m;
        vector < pair < pair < int, int >, int > > g;
        for(int i = 1; i <= n; i++){
                p[i][0] = i;
        }
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                if(get(x) != get(y)){
                        p[get(x)][0] = get(y);
                        v1[x].push_back({y, w});
                        v1[y].push_back({x, w});
                }
                else{
                        g.push_back({{x, y}, w});
                }
                v2[x].push_back({y, w});
                v2[y].push_back({x, w});
        }
        dfs(1, 1);
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;
                ans[i] = dip[x] + dip[y] - 2 * dip[lca(x, y)];
                A[i] = x;
                B[i] = y;
        }
        for(auto pp: g){
                int x = pp.fi.fi, y = pp.fi.se, w = pp.se;
                djk(x, dx);
                djk(y, dy);
                for(int i = 1; i <= q; i++){
                        ans[i] = min(ans[i], dx[A[i]] + dy[B[i]] + w);
                        ans[i] = min(ans[i], dx[B[i]] + dy[A[i]] + w);
                }
        }
        for(int i = 1; i <= q; i++){
                cout << ans[i] << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
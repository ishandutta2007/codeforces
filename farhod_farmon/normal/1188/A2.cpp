#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 1e9 + 7;

using namespace std;

vector < pair < pair < int, int >, int > > res;

void add(int x, int y, int w)
{
        res.push_back({{x, y}, w});
}

int n;
int r;
vector < pair < int, int > > v[N];
vector < pair < int, int > > g[N];

int make(int x, int p)
{
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                g[x].push_back({make(y.fi, x), y.fi});
        }
        if(g[x].empty()){
                return x;
        } else{
                return g[x][0].fi;
        }
}

void dfs(int x, int p, int r1, int r2, int w = 0)
{
        if(v[x].size() == 1){
                int r3 = x;
                add(r1, r3, w / 2);
                add(r2, r3, w / 2);
                add(r1, r2, - w / 2);
        } else{
                int r3 = g[x][0].fi, r4 = g[x][1].fi;
                add(r1, r3, w / 2);
                add(r2, r4, w / 2);
                add(r1, r2, - w / 2);
                add(r3, r4, - w / 2);
        }
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                if(y.fi == g[x][0].se){
                        r2 = g[x][1].fi;
                } else{
                        r2 = g[x][0].fi;
                }
                dfs(y.fi, x, r1, r2, y.se);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                v[y].push_back({x, w});
        }
        if(n == 2){
                add(1, 2, v[1][0].se);
        } else{
                r = 1;
                for(int i = 1; i <= n; i++){
                        if(v[i].size() == 2){
                                cout << "NO" << "\n";
                                return 0;
                        } else if(v[i].size() > 1){
                                r = i;
                        }
                }
                make(r, r);
                dfs(g[r][0].se, r, g[r][1].fi, g[r][2].fi, v[r][0].se);
                dfs(g[r][1].se, r, g[r][0].fi, g[r][2].fi, v[r][1].se);
                for(int i = 2; i < g[r].size(); i++){
                        dfs(g[r][i].se, r, g[r][0].fi, g[r][1].fi, v[r][i].se);
                        assert(v[r][i].fi == g[r][i].se);
                }
        }
        cout << "YES" << "\n";
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi.fi << ' ' << p.fi.se << " " << p.se << "\n";
        }
}
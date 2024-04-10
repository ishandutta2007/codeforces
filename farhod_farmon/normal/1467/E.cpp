#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int tim;
int a[N];
int dip[N];
int tin[N];
int tout[N];
int d[N];
set < int > S[N];
vector < int > v[N], g[N];

void dfs(int x, int p)
{
        d[x] = -1;
        tin[x] = ++tim;
        if(!g[a[x]].empty()){
                d[x] = g[a[x]].back();
        }
        g[a[x]].push_back(dip[x]);
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dip[y] = dip[x] + 1;
                dfs(y, x);
                d[x] = max(d[x], d[y]);
        }
        tout[x] = tim;
        S[a[x]].insert(tin[x]);
        g[a[x]].pop_back();
}

int res;

void solve(int x, int p)
{
        res += (d[x] < dip[x] && S[a[x]].size() == 1);

        int cnt = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                cnt += (d[y] >= dip[x]);
        }

        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                int good = 1;
                S[a[x]].erase(tin[x]);
                if(!S[a[x]].empty()){
                        good &= (tin[y] <= *S[a[x]].begin());
                        good &= (*(--S[a[x]].end()) <= tout[y]);
                }
                S[a[x]].insert(tin[x]);
                cnt -= (d[y] >= dip[x]);
                if(good && !cnt){
                        solve(y, x);
                }
                cnt += (d[y] >= dip[x]);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < pair < int, int > > g;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                g.push_back({a[i], i});
        }
        sort(g.begin(), g.end());
        for(int i = 0, j = 1; i < g.size(); i++){
                if(i > 0 && g[i].fi > g[i - 1].fi){
                        j += 1;
                }
                a[g[i].se] = j;
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        solve(1, 1);

        cout << res << "\n";
}
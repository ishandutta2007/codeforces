#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int res[N];
bool bad[N];
bool off[N];
vector < pair < int, int > > v[N];

void dfs(int x, int p)
{
        if(!bad[x]){
                for(auto y: v[x]){
                        off[res[y.se]] = 1;
                }
                int h = 1;
                for(auto y: v[x]){
                        while(off[h]){
                                h++;
                        }
                        if(!res[y.se]){
                                res[y.se] = h;
                                off[h] = 1;
                        }
                }
                for(auto y: v[x]){
                        off[res[y.se]] = 0;
                }
        }
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                dfs(y.fi, x);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back({y, i});
                v[y].push_back({x, i});
        }
        vector < pair < int, int > > g;
        for(int i = 1; i <= n; i++){
                g.push_back({v[i].size(), i});
        }
        sort(g.begin(), g.end());
        for(int i = 1; i <= k; i++){
                bad[g[n - i].se] = true;
        }
        dfs(1, 1);
        cout << g[n - k - 1].fi << "\n";
        for(int i = 1; i < n; i++){
                cout << max(1, res[i]) << " ";
        }
}
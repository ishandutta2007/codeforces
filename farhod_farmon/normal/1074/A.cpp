#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int m;
map < int, vector < pair < int, int > > > q;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        vector < int > v(n);
        for(int i = 0; i < n; i++){
                cin >> v[i];
        }
        for(int i = 0; i < m; i++){
                int x, l, r;
                cin >> l >> r >> x;
                q[x].push_back({l, r});
        }
        vector < int > g;
        for(auto p: q){
                auto f = p.se;
                sort(f.begin(), f.end());
                f.push_back({1e9 + 2, 1e9 + 2});
                if(f[0].fi > 1){
                        continue;
                }
                for(int i = 0; i + 1 < f.size(); i++){
                        if(f[i].se + 1 < f[i + 1].fi){
                                g.push_back(f[i].se);
                                break;
                        }
                }
        }
        sort(g.begin(), g.end());
        sort(v.begin(), v.end());
        v.push_back(1e9);
        int ans = 1e9;
        for(int i = 0, j = 0; i <= n; i++){
                while(j < g.size() && g[j] < v[i]){
                        j++;
                }
                ans = min(ans, i + (int)g.size() - j);
        }
        cout << ans << "\n";
}
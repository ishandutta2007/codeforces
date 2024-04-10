#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const long long mod = 998244353;

using namespace std;

int n;
long long k;
long long cnt;
vector < pair < int, long long > > v[N];
vector < long long > g, ch;

void dfs(int x, long long f = 0)
{
        ch.push_back(f);
        for(auto p: v[x]){
                dfs(p.fi, f ^ p.se);
        }
}

long long can(long long mask, long long gg)
{
        vector < pair < long long, int > > v;
        for(int i = 0; i < n; i++){
                g[i] = ch[i] & gg;
                if(v.empty() || v.back().fi != g[i]){
                        v.push_back({g[i], 1});
                }
                else{
                        v[v.size() - 1].se++;
                }
        }
        cnt = 0;
        if(mask == 0){
                cnt = -n;
        }
        for(int i = 0, j = 0; i < v.size(); i++){
                long long y = v[i].fi ^ mask;
                if(y > v[i].fi){
                        continue;
                }
                while(j + 1 < v.size() && v[j].fi < y){
                        j++;
                }
                while(j > 0 && v[j].fi > y){
                        j--;
                }
                if(v[j].fi == y){
                        cnt += 2ll * v[j].se * v[i].se;
                }
        }
        return cnt;
}


int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 2; i <= n; i++){
                int x;
                long long y;
                cin >> x >> y;
                v[x].push_back({i, y});
        }
        dfs(1);
        sort(ch.begin(), ch.end());
        g.resize(n);
        long long ans = 0, now = 1ll * n * n, gg = 0;
        for(long long i = 61; i >= 0; i--){
                ans ^= (1ll << i);
                gg ^= (1ll << i);
                long long g = can(ans, gg);
                if(now - g < k){
                        k -= now - g;
                        now = g;
                }
                else{
                        now -= g;
                        ans ^= (1ll << i);
                }
        }
        cout << ans << "\n";
}
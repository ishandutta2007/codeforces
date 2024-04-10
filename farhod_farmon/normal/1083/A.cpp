#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 300300;

using namespace std;

int n;
long long ans;
long long a[N];
vector < pair < int, long long > > v[N];

void dfs(int x, int p)
{
        long long best = 0;
        for(auto gg: v[x]){
                int y = gg.fi;
                long long w = gg.se;
                if(y == p){
                        continue;
                }
                dfs(y, x);
                ans = max(ans, a[x] + max(0ll, a[y] - w) + best);
                best = max(best, a[y] - w);
        }
        a[x] += best;
        ans = max(ans, a[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 2; i <= n; i++){
                int x, y, c;
                cin >> x >> y >> c;
                v[x].push_back({y, c});
                v[y].push_back({x, c});
        }
        dfs(1, 1);
        cout << ans << "\n";
}
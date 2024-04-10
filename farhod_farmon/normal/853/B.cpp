#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;
const int Q = 1001000;

using namespace std;

int n, m, k;
int cost[N];
int a[Q], b[Q];
long long pref[Q], suf[Q];
vector < pair < int, int > > A[Q], B[Q];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++){
                int d, x, y, z;
                cin >> d >> x >> y >> z;
                if(x > 0) A[d].push_back({x, z});
                else B[d].push_back({y, z});
        }

        long long inf = 1e7 + 2;
        for(int i = 1; i <= n; i++) cost[i] = inf;
        suf[Q - 1] = pref[0] = inf * n;
        for(int i = 1; i < Q; i++){
                pref[i] = pref[i - 1];
                a[i] = a[i - 1];
                for(auto p: A[i]){
                        pref[i] -= cost[p.fi];
                        if(cost[p.fi] == inf) a[i] += 1;
                        cost[p.fi] = min(cost[p.fi], p.se);
                        pref[i] += cost[p.fi];
                }
        }
        for(int i = 1; i <= n; i++) cost[i] = inf;
        for(int i = Q - 2; i >= 0; i--){
                suf[i] = suf[i + 1];
                b[i] = b[i + 1];
                for(auto p: B[i]){
                        suf[i] -= cost[p.fi];
                        if(cost[p.fi] == inf) b[i] += 1;
                        cost[p.fi] = min(cost[p.fi], p.se);
                        suf[i] += cost[p.fi];
                }
        }
        long long res = 1e18;
        for(int i = 1; i + k + 1 < Q; i++) if(a[i] == n && b[i + k + 1] == n) res = min(res, pref[i] + suf[i + k + 1]);

        if(res == 1e18) res = -1;
        cout << res << "\n";
}
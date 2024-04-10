#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int m;
int k;
int pos[N];
pair < int, int > a[N];
long long d[1 << 7][8];
long long f[1 << 7][8];
int cost[N][7];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        for(int i = 1; i <= n; i++) for(int j = 0; j < m; j++) cin >> cost[i][j];
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) pos[a[i].se] = i;

        long long inf = -1e18;
        for(int i = 0; i < (1 << m); i++) for(int j = 0; j <= m; j++) d[i][j] = f[i][j] = inf;
        d[0][0] = 0;
        for(int i = 1; i <= k; i++){
                d[0][0] += a[i].fi;
        }
        long long nc;
        for(int ii = 1; ii <= n; ii++){
                int i = a[ii].se;
                for(int j = 0, nj; j < (1 << m); j++){
                        for(int j2 = 0; j2 < m; j2++){
                                if(j & (1 << j2)) continue;
                                nj = j | (1 << j2);
                                for(int h = 0, nh; h < m; h++){
                                        nh = h;
                                        nc = d[j][h] + cost[i][j2];
                                        if(pos[i] <= k + h){
                                                nh += 1;
                                                nc -= a[pos[i]].fi;
                                                nc += a[k + nh].fi;
                                        }
                                        f[nj][nh] = max(f[nj][nh], nc);
                                }
                        }
                }
                for(int j = 0; j < (1 << m); j++) for(int h = 0; h <= m; h++){
                        d[j][h] = max(d[j][h], f[j][h]);
                        f[j][h] = inf;
                }
        }
        int mask = (1 << m) - 1;
        long long res = d[mask][0];
        for(int i = 1; i <= m; i++) res = max(res, d[mask][i]);

        cout << res << "\n";
}
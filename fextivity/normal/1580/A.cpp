#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 4e2 + 5;

int n, m;
bool a[N][N];

int pr[N][N], pc[N][N], pa[N][N];
int dif[N], pdif[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            char c; cin >> c; a[i][j] = c - '0';
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            pr[i][j] = pr[i][j - 1] + a[i][j];
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            pc[i][j] = pc[i - 1][j] + a[i][j];
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            pa[i][j] = a[i][j] + pa[i][j - 1] + pa[i - 1][j] - pa[i - 1][j - 1];
        }
    }
    int ans = n * m;
    ForE(d, 5, n){
        ForE(u, 1, d - 4){
            For(j, 1, m){
                dif[j] = (d - u - 1 - (pc[d - 1][j] - pc[u][j])) + (1 - a[d][j + 1] + pc[d - 1][j + 1] - pc[u][j + 1] + 1 - a[u][j + 1]) - (d - u - 1 - (pc[d - 1][j + 1] - pc[u][j + 1]));
                pdif[j] = pdif[j - 1] + dif[j];
            }
            int mxpdif = 0;
            ForE(j, 4, m){
                int tans = (d - u - 1 - (pc[d - 1][j] - pc[u][j])) + (1 - a[d][j - 1] + pc[d - 1][j - 1] - pc[u][j - 1] + 1 - a[u][j - 1]) + (1 - a[d][j - 2] + pc[d - 1][j - 2] - pc[u][j - 2] + 1 - a[u][j - 2]) + (d - u - 1 - (pc[d - 1][j - 3] - pc[u][j - 3]));
                ans = min(ans, tans + pdif[j - 4] - mxpdif);
                mxpdif = max(mxpdif, pdif[j - 3]);
            }
        }
    }
    cout << ans << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/
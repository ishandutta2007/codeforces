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

const int N = 3e2 + 5;

int n, m;
pii a[N * N];

int seat[N][N];
bool goodrow[N];

pii calcoor(int x){
    return make_pair((x - 1) / m + 1, x % m == 0 ? m : x % m);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n * m){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + n * m);

    ForE(i, 1, n){
        goodrow[i] = 0;
        ForE(j, 1, m){
            seat[i][j] = 0;
        }
    }
    pii pos = make_pair(1, 1), npos;
    int l = 1;
    ForE(i, 2, n * m + 1){
        if (a[i].fi != a[i - 1].fi){
            npos = calcoor(i - 1);
            if (pos.fi == npos.fi){
                ForE(j, l, i - 1){
                    seat[calcoor(j).fi][calcoor(j).se] = a[l + i - 1 - j].se;
                }
            }
            else{
                int cnttop = m - pos.se + 1, cntbot = npos.se;
                ForE(j, l, l + cnttop - 1){
                    seat[calcoor(j).fi][calcoor(j).se] = a[l + l + cnttop - 1 - j].se;
                }
                ForE(j, i - cntbot, i - 1){
                    seat[calcoor(j).fi][calcoor(j).se] = a[i - cntbot + i - 1 - j].se;
                }
                ForE(j, pos.fi + 1, npos.fi - 1){
                    goodrow[j] = 1;
                }
            }
            pos = calcoor(i);
            l = i;
        }
    }
    int ans = 0;
    ForE(i, 1, n){
        if (goodrow[i]){
            continue;
        }
        ForE(j, 1, m){
            ForE(k, j + 1, m){
                if (seat[i][j] < seat[i][k]){
                    ans++;
                }
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
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 5e3 + 5;

int n;
int a[N];

int cntpref[N][N], cntsuff[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(j, 1, n){
        cntpref[0][j] = 0;
    }
    ForE(i, 1, n){
        ForE(j, 1, n){
            cntpref[i][j] = cntpref[i - 1][j];
        }
        ForE(j, a[i], n){
            cntpref[i][j]++;
        }
    }

    ForE(j, 1, n){
        cntsuff[n + 1][j] = 0;
    }
    FordE(i, n, 1){
        ForE(j, 1, n){
            cntsuff[i][j] = cntsuff[i + 1][j];
        }
        ForE(j, a[i], n){
            cntsuff[i][j]++;
        }
    }

    ll ans = 0;
    ForE(l, 1, n){
        ForE(r, l + 1, n){
            ans += cntpref[l - 1][a[r]] * cntsuff[r + 1][a[l]];
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
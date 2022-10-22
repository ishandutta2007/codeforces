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

ll n;

ll fac[20];

ll ans;
int cnt[10];
int a[10];

void bt(int u){
    if (u == 10){
        int sum = 0;
        For(i, 0, 10){
            sum += a[i];
        }
        ll tans = fac[sum];
        For(i, 0, 10){
            tans /= fac[a[i]];
        }
        if (a[0]){
            ll sub = fac[sum - 1];
            For(i, 0, 10){
                sub /= (i == 0 ? fac[a[i] - 1] : fac[a[i]]);
            }
            tans -= sub;
        }
        ans += tans;
        return;
    }
    if (cnt[u]){
        ForE(i, 1, cnt[u]){
            a[u] = i;
            bt(u + 1);
        }
    }
    else{
        bt(u + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    fac[0] = 1;
    ForE(i, 1, 19){
        fac[i] = fac[i - 1] * i;
    }
    cin >> n;
    while (n){
        cnt[n % 10]++;
        n /= 10;
    }
    bt(0);
    cout << ans << endl;
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
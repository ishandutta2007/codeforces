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

const int N = 2e5 + 5, M = 8 + 2;

int lpf[N];
vi vprime;

void sieve(){
    For(i, 2, N){
        if (lpf[i] == 0){
            lpf[i] = i;
            vprime.emplace_back(i);
        }
        for (int j = 0; j < isz(vprime) and vprime[j] <= lpf[i] and vprime[j] * i < N; j++){
            lpf[vprime[j] * i] = vprime[j];
        }
    }
}

int n, q;
int a[N];

int m;
vi vdiv;
multiset <ll> stt[M];
ll b[M][N];

inline ll find_max(){
    ll ans = 0;
    For(i, 0, m){
        ans = max(ans, *stt[i].rbegin());
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
sieve();
int tests; cin >> tests; while (tests--){
    cin >> n >> q;
    For(i, 0, n){
        cin >> a[i];
    }

    vdiv.clear();
    For(i, 1, n){
        if (n % i == 0 and lpf[n / i] == n / i){
            vdiv.emplace_back(i);
        }
    }
    m = isz(vdiv);

    For(i, 0, m){
        For(j, 0, vdiv[i]){
            b[i][j] = 0;
        }
        For(j, 0, n){
            b[i][j % vdiv[i]] += a[j];
        }
        stt[i].clear();
        For(j, 0, vdiv[i]){
            b[i][j] *= vdiv[i];
            stt[i].emplace(b[i][j]);
        }
    }

    cout << find_max() << endl;
    while (q--){
        int idx, val; cin >> idx >> val; idx--;
        ll delta = val - a[idx];
        For(i, 0, m){
            int j = idx % vdiv[i];
            stt[i].erase(stt[i].find(b[i][j]));
            b[i][j] += delta * vdiv[i];
            stt[i].emplace(b[i][j]);
        }
        a[idx] = val;
        cout << find_max() << endl;
    }
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
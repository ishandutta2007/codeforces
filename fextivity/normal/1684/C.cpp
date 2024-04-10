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

int n, m;
vvi a;

vvi b;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    a.assign(n, vi(m));

    For(i, 0, n){
        For(j, 0, m){
            cin >> a[i][j];
        }
    }

    b = a;
    For(i, 0, n){
        sort(bend(b[i]));
    }
    int ans1 = m, ans2 = m;

    For(j, 0, m){
        bool ck = 0;
        For(i, 0, n){
            ck |= (a[i][j] != b[i][j]);
        }
        if (!ck){
            continue;
        }
        if (ans1 == m){
            ans1 = j;
        }
        else if (ans2 == m){
            ans2 = j;
        }
    }
    if (ans1 == m){
        ans1 = 0; ans2 = 0;
    }
    For(i, 0, n){
        swap(a[i][ans1], a[i][ans2]);
    }
    bool ck = 1;
    For(i, 0, n){
        For(j, 0, m){
            ck &= (a[i][j] == b[i][j]);
        }
    }
    if (ck){
        cout << ans1 + 1 << ' ' << ans2 + 1 << endl;
    }
    else{
        cout << -1 << endl;
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
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

const int N = 1e5 + 5;

int n;
int a[N];

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

    sort(a + 1, a + n + 1);
    {
        bool ck = 1;
        ForE(i, 2, n){
            ck &= (a[i] == a[i - 1]);
        }
        if (ck){
            cout << "YES" << endl;
            continue;
        }
    }
    bool has1 = 0;
    ForE(i, 1, n){
        has1 |= (a[i] == 1);
    }
    if (!has1){
        cout << "YES" << endl;
        continue;
    }
    if (a[1] == 0){
        cout << "NO" << endl;
        continue;
    }
    bool ans = 1;
    ForE(i, 2, n){
        if (a[i - 1] + 1 == a[i]){
            ans = 0;
        }
    }
    if (ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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
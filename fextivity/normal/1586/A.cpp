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

const int N = 1e2 + 5;

int n;
int a[N];

bool isprime(int x){
    if (x <= 1){
        return 0;
    }
    if (x <= 3){
        return 1;
    }
    if (x % 2 == 0 or x % 3 == 0){
        return 0;
    }
    for (int i = 5; i * i <= x; i += 6){
        if (x % i == 0 or x % (i + 2) == 0){
            return 0;
        }
    }
    return 1;
}

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

    int sum = 0;
    ForE(i, 1, n){
        sum += a[i];
    }
    if (!isprime(sum)){
        cout << n << endl;
        ForE(i, 1, n){
            cout << i << ' ';
        } cout << endl;
        continue;
    }
    cout << n - 1 << endl;
    bool ck = 1;
    ForE(i, 1, n){
        if (ck and a[i] % 2 == 1){
            ck = 0;
            continue;
        }
        cout << i << ' ';
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
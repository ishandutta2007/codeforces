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

const int N = 2e5 + 5;

vi divisors[N];

int n;
int a[N];

int cnt[30], ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
For(i, 1, N){
    for (int j = i; j < N; j += i){
        divisors[j].emplace_back(i);
    }
}
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    memset(cnt, 0, sizeof(cnt));
    ForE(i, 1, n){
        For(j, 0, 30){
            if (a[i] & (1 << j)){
                cnt[j]++;
            }
        }
    }
    ForE(i, 1, n){
        ans[i] = 0;
    }
    For(j, 0, 30){
        if (!cnt[j]){
            ForE(i, 1, n){
                ans[i]++;
            }
        }
        Fora(x, divisors[cnt[j]]){
            ans[x]++;
        }
    }
    ForE(i, 1, n){
        if (ans[i] == 30){
            cout << i << ' ';
        }
    } cout << endl;
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
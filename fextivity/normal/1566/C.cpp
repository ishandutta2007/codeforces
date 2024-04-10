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

const int N = 1e5 + 5, M = 17, inf = 1e9 + 7;

int n;
string s, t;

int dp[N][M];

int caldp(int l, int r){
    if (l > r){
        return -inf;
    }
    int z = __builtin_clz(r - l + 1) ^ 31;
    return max(dp[r][z], dp[l + (1 << z) - 1][z]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    cin >> s; s = ' ' + s;
    cin >> t; t = ' ' + t;
    ForE(i, 0, n){
        For(j, 0, M){
            dp[i][j] = 0;
        }
    }
    int pos1 = 0, pos0 = 0;
    ForE(i, 1, n){
        if (s[i] == '0'){
            pos0 = i;
        }
        else{
            pos1 = i;
        }
        if (t[i] == '0'){
            pos0 = i;
        }
        else{
            pos1 = i;
        }
        int t = caldp(0, min(pos0, pos1) - 1) + 2;
        if (pos0 != pos1){
            t = max(t, caldp(min(pos0, pos1), i - 1) + (pos0 == i ? 1 : 0));
        }
        dp[i][0] = t;
        For(j, 1, M){
            if (i - (1 << j) + 1 >= 0){
                dp[i][j] = max(dp[i][j - 1], dp[i - (1 << (j - 1))][j - 1]);
            }
        }
    }
    cout << dp[n][0] << endl;
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
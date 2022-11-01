#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const ll MOD = 1e9 + 7;
const ll PHI = MOD - 1;

vvl Mult(const vvl& a, const vvl& b) {
    int n = (int) a.size();
    vvl c(n, vl(n));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= PHI;
            }
        }
    }
    return c;
}

vvl BinPow(const vvl& a, ll pow) {
    if (!pow) {
        int n = (int)a.size();
        vvl c(n, vl(n));
        for (int i = 0; i < n; ++i) {
            c[i][i] = 1;
        }
        return c;
    }
    if (pow & 1) {
        return Mult(a, BinPow(a, pow - 1));
    } else {
        vvl tmp = BinPow(a, pow / 2);
        return Mult(tmp, tmp);
    }
}

ll BinPow(ll a, ll pow) {
    if (!pow) {
        return 1;
    }
    if (pow & 1) {
        return BinPow(a, pow - 1) * a % MOD;
    } else {
        ll tmp = BinPow(a, pow / 2);
        return tmp * tmp % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll x, y, z, c;
    cin >> x >> y >> z >> c;
    x %= MOD;
    y %= MOD;
    z %= MOD;
    c %= MOD;
    ll w = BinPow(c, 2);
    vvl mat = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    mat = BinPow(mat, n - 3);
    ll ans = BinPow(x, mat[0][2]);
    ans *= BinPow(y, mat[0][1]);
    ans %= MOD;
    ans *= BinPow(z, mat[0][0]);
    ans %= MOD;
    mat = {{1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}};
    mat = BinPow(mat, n - 3);
    ans *= BinPow(w, mat[0][3] + mat[0][4]);
    ans %= MOD;
    cout << ans;
    return 0;
}

/*
7 1 1 1 1

 */
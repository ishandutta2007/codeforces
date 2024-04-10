#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 107;
const int N = 16;
const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

namespace matrix {
struct Matrix {
    int n, m;
    int a[N][N];
    Matrix(int n_, int m_) {
        n = n_;
        m = m_;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a[i][j] = 0;
            }   
        }   
    }
    int* operator [](int i) {
        return a[i];
    }
    Matrix operator *(Matrix p) {
        Matrix ans(n, p.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    ans[i][j] = mod(ans[i][j] + a[i][k] * p[k][j]);
                }
            }   
        }
        return ans;
    }   
};

Matrix fp(Matrix a, int p) {
    if (p == 0) {
        Matrix ans(a.n, a.n);
        for (int i = 0; i < a.n; ++i) ans[i][i] = 1;
        return ans;
    }   
    auto t = fp(a, p >> 1);
    if (p & 1) return t * t * a;
    else return t * t;
}
};

int n, k;
int l[MAXN], r[MAXN], h[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i] >> h[i];
    }
    r[n - 1] = k;
}

using namespace matrix;

Matrix dp(n, 1);

void add(int num) {
    Matrix m(h[num] + 1, h[num] + 1);
    for (int i = 0; i <= h[num]; ++i) {
        if (i) m[i][i - 1] = 1;
        m[i][i] = 1;
        if (i + 1 <= h[num]) m[i][i + 1] = 1;
    }
    m = fp(m, r[num] - l[num]);
    
    for (int i = h[num] + 1; i < N; ++i) dp[i][0] = 0;
    dp = m * dp;
}

void solve() {
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        add(i);
    }
}

void print() {
    cout << dp[0][0] << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}
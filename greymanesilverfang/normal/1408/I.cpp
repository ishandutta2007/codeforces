#include <cstdio>
#include <algorithm>
const int LIM = 12, LOG = 16, N = 40, MOD = 998244353;
int f[N] = {1};

int addmod(int x) {
    return x < MOD ? x : x - MOD;
}
int add(int x, int y) {
    return addmod(x + y);
}
int submod(int x) {
    return x < 0 ? x + MOD : x;
}
int sub(int x, int y) {
    return submod(x - y);
}
int mul(int x, int y) {
    return 1LL * x * y % MOD;
}
int pow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = mul(res, x);
        x = mul(x, x);
        y /= 2;
    }
    return res;
}
int inv(int x) {
    return pow(x, MOD - 2);
}

struct Data {
    int len, mat[N][N], tmp[N][N];
    void init(int num) {
        len = num;
        for (int i = 0; i <= LOG; ++i)
            for (int j = 0; j < len; ++j)
                mat[i][j] = 0;
        mat[0][0] = 1;
    }
    void hadamard() {
        for (int i = 1; i < len; i *= 2) {
            for (int j = 0; j <= LOG; ++j)
                for (int k = 0; k < len; ++k)
                    if (k & i) {
                        tmp[j][k ^ i] = add(mat[j][k ^ i], mat[j][k]);
                        tmp[j][k] = sub(mat[j][k ^ i], mat[j][k]);
                    }
            std::swap(mat, tmp);
        }
    }
    void invert() {
        for (int i = 0; i <= LOG; ++i)
            for (int j = 0; j < len; ++j)
                mat[i][j] = mul(mat[i][j], inv(len));
    }
    void hadamardInv() {
        hadamard();
        invert();
    }
    void update(const Data &d) {
        for (int i = 0; i <= LOG; ++i)
            for (int j = 0; j < len; ++j) {
                tmp[i][j] = 0;
                for (int k = 0; k <= i; ++k)
                    tmp[i][j] = add(tmp[i][j], mul(mat[k][j], d.mat[i - k][j]));
            }
        std::swap(mat, tmp);
    }
} prep[N], tmp[N], dp[2][N], res[1 << LIM + 1];

void precalc() {
    for (int i = 1; i <= LOG; ++i)
        f[i] = mul(f[i - 1], i);
    for (int i = 0; i < LOG; ++i) {
        prep[i].init(LOG << 1);
        int num = i + LOG;
        for (int j = 1; j <= LOG; ++j)
            prep[i].mat[j][num ^ num - j] = inv(f[j]);
        prep[i].hadamard();
    }
    for (int i = 0; i <= LIM; ++i) {
        tmp[i].init(LOG << 1);
        tmp[i].hadamard();
        dp[0][i].init(LOG);
        dp[1][i].init(LOG);
    }
}

void recurse(int mask, int h, Data dat) {
    for (int i = 0; i <= 1; ++i) {
        Data tmp = dat;
        tmp.update(dp[i][h]);
        if (i == 1)
            mask ^= (1 << h + 1) - 1;
        if (h > 0)
            recurse(mask, h - 1, tmp);
        else {
            tmp.hadamardInv();
            res[mask] = tmp;
        }
    }
}

void solve() {
    Data dat;
    dat.init(LOG);
    dat.hadamard();
    recurse(0, LIM, dat);
}

int main() {
    precalc();
    int n, k, c; scanf("%d%d%d", &n, &k, &c);
    int xum = 0;
    for (int i = 1; i <= n; ++i) {
        int a; scanf("%d", &a);
        xum ^= a;
        tmp[__builtin_ctz(a / LOG + (1 << LIM))].update(prep[a % LOG]);
    }
    for (int i = 0; i <= LIM; ++i) {
        tmp[i].hadamardInv();
        for (int j = 0; j <= LOG; ++j)
            for (int k = 0; k < LOG; ++k) {
                dp[0][i].mat[j][k] = tmp[i].mat[j][k];
                dp[1][i].mat[j][k] = tmp[i].mat[j][k + LOG];
            }
        dp[0][i].hadamard();
        dp[1][i].hadamard();
    }
    solve();
    int coeff = mul(f[k], inv(pow(n, k)));
    for (int i = 0; i < 1 << c; ++i) {
        int num = i ^ xum;
        printf("%d ", mul(coeff, res[num / LOG].mat[k][num % LOG]));
    }
    printf("\n");
}
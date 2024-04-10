#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct matrix {
    int rows, cols, MOD;
    int **c;

    void init() {
        c = new int*[rows];
        for(int i = 0; i < rows; i++)
            c[i] = new int[cols];
    }
    void clean() {
        for(int i = 0; i < rows; i++)
            delete [] c[i];
        delete [] c;
    }

    matrix(int row, int col, int M = 1000000007) : rows(row), cols(col), MOD(M) {
        init();
        for(int i = 0; i < rows; i++)
            memset(c[i], 0, cols * sizeof(int));
    }

    matrix(const matrix &o) : rows(o.rows), cols(o.cols), MOD(o.MOD) {
        init();
        for(int i = 0; i < rows; i++)
            memcpy(c[i], o.c[i], cols * sizeof(int));
    }

    matrix& operator = (const matrix &o) {
        clean();
        rows = o.rows; cols = o.cols; MOD = o.MOD;
        init();
        for(int i = 0; i < rows; i++)
            memcpy(c[i], o.c[i], cols * sizeof(int));
        return *this;
    }

    ~matrix() { clean(); }

    void print() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                printf("%d ", c[i][j]);
            puts("");
        }
    }

    matrix operator + (matrix b) const {
        assert(rows == b.rows && cols == b.cols);
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++) {
                b.c[i][j] += c[i][j];
                if(b.c[i][j] >= MOD) b.c[i][j] -= MOD;
            }
        return b;
    }

    matrix operator - (matrix b) const {
        assert(rows == b.rows && cols == b.cols);
        matrix ret = *this;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++) {
                ret.c[i][j] -= b.c[i][j];
                if(ret.c[i][j] < 0) ret.c[i][j] += MOD;
            }
        return ret;
    }

    matrix operator * (ll k) const {
        matrix ret = *this;
        k %= MOD;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                ret.c[i][j] = (1LL * ret.c[i][j] * k) % MOD;
        return ret;
    }

    matrix operator % (matrix b) const {
        assert(cols == b.rows);
        matrix ret(rows, b.cols, MOD);
        ll MOD2 = 1LL * MOD * MOD;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < b.cols; j++) {
                ll sum = 0;
                for(int k = 0; k < cols; k++) {
                    sum += (1LL * c[i][k] * b.c[k][j]);
                    if(sum >= MOD2) sum -= MOD2;
                }
                ret.c[i][j] = sum % MOD;
            }
        }
        return ret;
    }

    matrix operator ^ (ll exp) const {
        matrix ret = matrix(rows, cols, MOD), base = *this;
        for(int i = 0; i < rows; i++) ret.c[i][i] = 1;

        while(exp) {
            if(exp & 1) ret = ret % base;
            exp >>= 1;
            if(exp) base = base % base;
        }
        return ret;
    }
};

int n, k, m, dim;

int t(int m, int r) {
    return m * (k + 1) + r;
}

int main() {
    scanf("%d %d %d", &n, &k, &m);

    dim = (k+1)*(1<<m);
    matrix mt(dim, dim);

    for(int msk = 0; msk < (1<<m); msk++) {
        mt.c[t(msk, 0)][t(msk, 0)] = 1;
        for(int rem = 1; rem <= k; rem++) {
            int nmsk = ((msk << 1) & ((1 << m) - 1));
            mt.c[t(msk, rem)][t(nmsk, rem)] = 1;
            mt.c[t(msk, rem)][t(nmsk | 1, rem - 1)] = (1LL + __builtin_popcount(msk));
        }
    }
    mt  = (mt ^ n);

    ll ans = 0;
    for(int i = 0; i < (1<<m); i++) {
        ans += mt.c[t(0, k)][t(i, 0)];
        if(ans >= mt.MOD) ans -= mt.MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
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

    int* operator [] (int row) {
        return c[row];
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

    matrix operator ^ (ll exp) const { //matrix^0 = identity
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

const ll MOD = 1000000007;
ll n, k, coef[50][50], ii[50], ifi[50], if1[50], cnt = 3, SZ = 130;
vector<pair<int, int>> c[220];

int main() {
    scanf("%lld %lld", &n, &k);
    if(n < 3) {
        if(n == 1) puts("1");
        if(n == 2) printf("%lld\n", (1LL + (2LL << k)) % MOD);
        return 0;
    }

    coef[0][0] = 1;
    for(int i = 1; i <= k; i++) {
        coef[i][0] = coef[i][i] = 1;
        for(int j = 1; j < i; j++)
            coef[i][j] = (coef[i-1][j] + coef[i-1][j-1]) % MOD;
    }

    for(int i = 0; i <= k; i++) ii[i] = cnt++;
    for(int i = 0; i <= k; i++) ifi[i] = cnt++;
    for(int i = 0; i <= k; i++) if1[i] = cnt++;

    matrix mat(SZ, SZ);
    for(int j = 0; j <= k; j++) {
        if(j == 0) mat[ii[j]][ii[j]] = 1;
        else for(int p = 0; p <= k; p++) {
            mat[ii[j]][ii[p]] = coef[j][p];
        }
    }
    for(int j = 0; j <= k; j++) {
        if(j == 0) {
            mat[ifi[j]][ifi[j]] = 1;
            mat[ifi[j]][if1[j]] = 1;
        }
        else for(int p = 0; p <= k; p++) {
            mat[ifi[j]][ifi[p]] = coef[j][p];
            mat[ifi[j]][if1[p]] = coef[j][p];
        }
    }
    for(int j = 0; j <= k; j++) {
        if(j == 0) {
            mat[if1[j]][ifi[j]] = 1;
        }
        else for(int p = 0; p <= k; p++) {
            mat[if1[j]][ifi[p]] = coef[j][p];
        }
    }

    mat[0][0] = 1;
    for(int p = 0; p <= k; p++) {
        mat[0][ifi[p]] = coef[k][p];
        mat[0][if1[p]] = coef[k][p];
    }

    matrix col(SZ, 1);
    col[0][0] = (1LL + (2LL << k)) % MOD;
    for(int j = 0; j <= k; j++) {
        col[ii[j]][0] = (1LL << j) % MOD;
    }
    for(int j = 0; j <= k; j++) {
        col[ifi[j]][0] = (2LL << j) % MOD;
    }
    for(int j = 0; j <= k; j++) {
        col[if1[j]][0] = (1LL << j) % MOD;
    }

    matrix res = (mat ^ (n - 2)) % col;
    printf("%d\n", res[0][0]);
    return 0;
}
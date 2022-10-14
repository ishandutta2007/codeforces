#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 150;

struct Matrix {
    Matrix() {
        memset(bits, 0, sizeof(bits));
    }

    inline bool at(int i, int j) const {
        return bits[i][j >> 5] >> (j & 31) & 1;
    }

    void set(int i, int j) {
        bits[i][j >> 5] |= 1U << (j & 31);
    }

    unsigned bits[N][5];
};

int n, m, a[N], b[N], d[N], o[N];

bool by_d(int i, int j) {
    return d[i] < d[j];
}

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int j = 0; j < n; ++ j) {
        unsigned tmp[5];
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < n; ++ i) {
            tmp[i >> 5] |= b.at(i, j) << (i & 31);
        }
        for (int i = 0; i < n; ++ i) {
            bool found = false;
            for (int k = 0; k < 5; ++ k) {
                found |= a.bits[i][k] & tmp[k];
            }
            if (found) {
                c.bits[i][j >> 5] |= 1U << (j & 31);
            }
        }
    }
    return c;
}

const int LIMIT = 1e9 + 200;

Matrix cur, trans, id;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        id.set(i, i);
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d%d", a + i, b + i, d + i);
        a[i] --;
        b[i] --;
        o[i] = i;
    }
    std::sort(o, o + m, by_d);
    cur.set(0, 0);
    trans.set(n - 1, n - 1);
    int result = 0;
    int best = LIMIT;
    if (d[o[0]] == 0) {
        for (int i = 0; i < m; ++ i) {
            trans.set(a[o[i]], b[o[i]]);
            int limit = LIMIT;
            if (i + 1 < m) {
                limit = d[o[i + 1]];
            }
            std::vector<Matrix> powers;
            powers.push_back(trans);
            for (int j = 1; (1 << j) <= limit - result; ++ j) {
                powers.push_back(powers[j - 1] * powers[j - 1]);
            }
            for (int j = (int)powers.size() - 1; j >= 0; -- j) {
                if (result + (1 << j) <= limit) {
                    Matrix tmp = cur * powers[j];
                    if (!tmp.at(0, n - 1)) {
                        result += 1 << j;
                        cur = tmp;
                    } else {
                        best = std::min(best, result + (1 << j));
                    }
                }
            }
        }
    }
    if (best < LIMIT) {
        printf("%d\n", best);
    } else {
        puts("Impossible");
    }
    return 0;
}
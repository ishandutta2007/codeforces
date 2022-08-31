#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef vector< vector< int > > TMatrix;

const int MOD = 12345;

int place(vector< int > &noks, vector< int > &ns) {
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (noks[i] == -1) {
            continue;
        }
        ans = ans * noks[i] + (ns[i] % noks[i]);
    }
    return ans;
}

int nod(int x, int y) {
    if (x == 0) {
        return y;
    }
    return nod(y % x, x);
}

void fill_matrix(TMatrix &matrix, vector< int > &noks, vector< int > &cur, int pr, int i) {
    if (i == 26) {
        int col = place(noks, cur);
        for (int j = 0; j < 26; ++j) {
            if (noks[j] == -1) {
                continue;
            }
            ++cur[j];
            ++matrix[col][place(noks, cur)];
            --cur[j];
        }
        return;
    }

    if (noks[i] == -1) {
        fill_matrix(matrix, noks, cur, pr, i + 1);
    }
    for (int j = 0; j < noks[i]; ++j) {
        cur[i] = j;
        fill_matrix(matrix, noks, cur, pr, i + 1);
    }
    cur[i] = 0;
}

TMatrix E(size_t n) {
    TMatrix res(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    return res;
}

TMatrix mmul(TMatrix &a, TMatrix &b) {
    int n = a.size();
    TMatrix c(n, vector< int >(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD; 
            }
        }
    }
    return c;
}

TMatrix deg(TMatrix &matrix, long long n) {
    if (n == 0) {
        return E(matrix.size());
    }

    TMatrix res = deg(matrix, n / 2);
    res = mmul(res, res);
    if (n % 2 == 1) {
        res = mmul(res, matrix);
    }
    
    return res;
}

int count_answer(TMatrix &matrix, vector< int > &noks, vector< vector< int > > &res,
                 vector< int > &cur, int i) {
    if (i == 26) {
        int ans = 0;
        int type = place(noks, cur);
        return matrix[type][0];
    }

    int ans = 0;
    if (noks[i] == -1) {
        return count_answer(matrix, noks, res, cur, i + 1);
    }
    for (int j = 0; j < noks[i]; ++j) {
        bool ok = false;
        for (size_t k = 0; k < res[i].size(); ++k) {
            if (j % res[i][k] == 0) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cur[i] = j;
            ans = (ans + count_answer(matrix, noks, res, cur, i + 1)) % MOD;
        }
    } 

    cur[i] = 0;
    return ans;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;
    vector< vector< int > > res(26);
    vector< int > noks(26, -1);
    vector< int > cur(26, 0);
    int pr = 1;
    for (int i = 0; i < k; ++i) {
        string s;
        int x;
        cin >> s >> x;
        int type = s[0] - 'A';
        if (x == 1) {
            res[type].clear();
            noks[type] = 1;
        }
        if (noks[type] == -1) {
            noks[type] = 1;
        }
        noks[type] *= x;
        pr *= x;
        res[type].push_back(x);
    }

    TMatrix matrix(pr, vector< int >(pr, 0));

    fill_matrix(matrix, noks, cur, pr, 0);
    TMatrix fmatrix = deg(matrix, n);

    int ans = count_answer(fmatrix, noks, res, cur, 0);
    cout << ans << '\n';

    return 0;
}
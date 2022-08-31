#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

const long long P = 777777777;

typedef vector< vector<long long> > Matrix;

Matrix mul(const Matrix &a, const Matrix &b) {
    Matrix c(3, vector<long long>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= P;
            }
        }
    }
    return c;
}

const int MAXN = 1 << 17;

void change(vector<long long> &tree, int root, int L, int R, int i, long long x) {
    if (L > i || R <= i) {
        return;
    }
    if (L == i && i + 1 == R) {
        tree[root] = x;
        return;
    }
    int M = (L + R) / 2;
    change(tree, 2 * root + 1, L, M, i, x);
    change(tree, 2 * root + 2, M, R, i, x);
    tree[root] = (tree[2 * root + 1] * tree[2 * root + 2]) % P;
}

long long ways(int f, int l, int d, const vector<Matrix> &degs) {
    long long ans = 0;

    if (f == -1) {
        --d;
    }
    if (l == -1) {
        --d;
    }

    for (int i = (f == -1 ? 0 : f); i < (f == -1 ? 3 : f + 1); ++i) {
        for (int j = (l == -1 ? 0 : l); j < (l == -1 ? 3 : l + 1); ++j) {
            ans += degs[d][i][j];
            ans %= P;
        }
    }
    return ans;
}

int main() {
	fout.precision(10);
	fout << fixed;

    int N, M;
    fin >> N >> M;

    Matrix w(3, vector<long long>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            fin >> w[i][j];
        }
    }

    vector<Matrix> degs(N + 1);
    degs[0].assign(3, vector<long long>(3));
    for (int i = 0; i < 3; ++i) {
        degs[0][i][i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        degs[i] = mul(degs[i - 1], w);
    }

    vector<int> arr(N + 2, -1);
    set<int> poss;
    poss.insert(0);
    poss.insert(N + 1);
    vector<long long> tree(2 * MAXN + 1, 1);

    change(tree, 0, 0, N + 1, 0, ways(-1, -1, N + 1, degs));

    for (int i = 0; i < M; ++i) {
        int x, v;
        fin >> x >> v;
        --v;
        arr[x] = v;
        int left = *(--poss.lower_bound(x));
        int right = *poss.upper_bound(x);            
        if (v >= 0) {
            change(tree, 0, 0, N + 1, left, ways(arr[left], v, x - left, degs));
            change(tree, 0, 0, N + 1, x, ways(v, arr[right], right - x, degs));
            poss.insert(x);
        } else {
            change(tree, 0, 0, N + 1, left, ways(arr[left], arr[right], right - left, degs));
            change(tree, 0, 0, N + 1, x, 1);
            poss.erase(x);
        }
        fout << tree[0] << '\n';
    }

	return 0;
}
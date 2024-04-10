#include <bits/stdc++.h>
using namespace std;

const int maxn = 1510;
int n, m, a[maxn][maxn], b[maxn][maxn], d[maxn], ord[maxn];
vector<int> G[maxn], Q;
bool used[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] > b[i + 1][j]) d[j]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!d[i]) Q.push_back(i);
    }
    auto solve = [&](int r) {
        used[r] = 1;
        for (int i = 1; i <= m; i++) {
            if (b[r][i] > b[r + 1][i] && !--d[i]) Q.push_back(i);
        }
    };
    for (int foo = 0; foo < Q.size(); foo++) {
        int c = Q[foo];
        for (int i = 1; i < n; i++) {
            if (!used[i] && b[i][c] ^ b[i + 1][c]) solve(i);
        }
    }
    reverse(Q.begin(), Q.end());
    iota(ord + 1, ord + n + 1, 1);
    for (int c : Q) {
        stable_sort(ord + 1, ord + n + 1, [&](int i, int j) {
            return a[i][c] < a[j][c];
        });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[ord[i]][j] ^ b[i][j]) puts("-1"), exit(0);
        }
    }
    printf("%d\n", Q.size());
    for (int x : Q) printf("%d " , x);
    return 0;
}
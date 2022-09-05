#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, q, a[maxn][maxn], lb[maxn], rb[maxn];
int U[maxn][maxn], D[maxn][maxn], L[maxn][maxn], R[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            U[i][j] = a[i][j] ? U[i - 1][j] + 1 : 0;
            L[i][j] = a[i][j] ? L[i][j - 1] + 1 : 0;
        }
        for (int j = m; j; j--) {
            R[i][j] = a[i][j] ? R[i][j + 1] + 1 : 0;
        }
    }
    for (int i = n; i; i--) {
        for (int j = 1; j <= m; j++) {
            D[i][j] = a[i][j] ? D[i + 1][j] + 1 : 0;
        }
    }
    while (q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            a[x][y] ^= 1;
            for (int i = 1; i <= n; i++) {
                U[i][y] = a[i][y] ? U[i - 1][y] + 1 : 0;
            }
            for (int i = n; i; i--) {
                D[i][y] = a[i][y] ? D[i + 1][y] + 1 : 0;
            }
            for (int i = 1; i <= m; i++) {
                L[x][i] = a[x][i] ? L[x][i - 1] + 1 : 0;
            }
            for (int i = m; i; i--) {
                R[x][i] = a[x][i] ? R[x][i + 1] + 1 : 0;
            }
        } else {
            int ans = 0;
            stack<int> st;

            for (int i = 1; i <= n; i++) {
                while (!st.empty() && L[st.top()][y] >= L[i][y]) st.pop();
                lb[i] = st.empty() ? 1 : (st.top() + 1), st.push(i);
            }
            while (!st.empty()) st.pop();
            for (int i = n; i; i--) {
                while (!st.empty() && L[st.top()][y] >= L[i][y]) st.pop();
                rb[i] = st.empty() ? n : (st.top() - 1), st.push(i);
            }
            for (int i = 1; i <= n; i++) if (lb[i] <= x && rb[i] >= x) {
                ans = max(ans, (rb[i] - lb[i] + 1) * L[i][y]);
            }

            while (!st.empty()) st.pop();
            for (int i = n; i; i--) {
                while (!st.empty() && R[st.top()][y] >= R[i][y]) st.pop();
                rb[i] = st.empty() ? n : (st.top() - 1), st.push(i);
            }
            while (!st.empty()) st.pop();
            for (int i = 1; i <= n; i++) {
                while (!st.empty() && R[st.top()][y] >= R[i][y]) st.pop();
                lb[i] = st.empty() ? 1 : (st.top() + 1), st.push(i);
            }
            for (int i = 1; i <= n; i++) if (lb[i] <= x && rb[i] >= x) {
                ans = max(ans, (rb[i] - lb[i] + 1) * R[i][y]);
            }

            while (!st.empty()) st.pop();
            for (int i = 1; i <= m; i++) {
                while (!st.empty() && U[x][st.top()] >= U[x][i]) st.pop();
                lb[i] = st.empty() ? 1 : (st.top() + 1), st.push(i);
            }
            while (!st.empty()) st.pop();
            for (int i = m; i; i--) {
                while (!st.empty() && U[x][st.top()] >= U[x][i]) st.pop();
                rb[i] = st.empty() ? m : (st.top() - 1), st.push(i);
            }
            for (int i = 1; i <= m; i++) if (lb[i] <= y && rb[i] >= y) {
                ans = max(ans, (rb[i] - lb[i] + 1) * U[x][i]);
            }

            while (!st.empty()) st.pop();
            for (int i = m; i; i--) {
                while (!st.empty() && D[x][st.top()] >= D[x][i]) st.pop();
                rb[i] = st.empty() ? m : (st.top() - 1), st.push(i);
            }
            while (!st.empty()) st.pop();
            for (int i = 1; i <= m; i++) {
                while (!st.empty() && D[x][st.top()] >= D[x][i]) st.pop();
                lb[i] = st.empty() ? 1 : (st.top() + 1), st.push(i);
            }
            for (int i = 1; i <= m; i++) if (lb[i] <= y && rb[i] >= y) {
                ans = max(ans, (rb[i] - lb[i] + 1) * D[x][i]);
            }

            printf("%d\n", ans);
        }
    }
    return 0;
}
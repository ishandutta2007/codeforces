#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, X, a[maxn], b[maxn], c[maxn], d[maxn], tr[maxn];
long long ans;
vector<int> M[maxn];
vector<pair<int, int>> Q[maxn];

void add(int p) {
    for (; p <= X; p += p & -p) tr[p]++;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += tr[p];
    return s;
}

int main() {
    scanf("%d %d %d", &n, &m, &X);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i] = min(a[i], X);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]), b[i] = min(b[i], X);
    }
    auto init = [&](int n, int *a, int *c) {
        static int mx[20][maxn], lb[maxn], rb[maxn];
        for (int i = 1; i <= n; i++) {
            mx[0][i] = a[i], lb[i] = rb[i] = 0;
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            }
        }
        auto query = [&](int l, int r) {
            int k = log2(r - l + 1);
            return max(mx[k][l], mx[k][r - (1 << k) + 1]);
        };
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.top()] > a[i]) rb[st.top()] = i, st.pop();
            if (!st.empty()) lb[i] = st.top();
            st.push(i);
        }
        for (int i = 1; i <= n; i++) {
            c[i] = min(!lb[i] ? X : query(lb[i], i), !rb[i] ? X : query(i, rb[i]));
        }
    };
    init(n, a, c), init(m, b, d);
    for (int i = 1; i <= n; i++) {
        Q[X - c[i]].emplace_back(a[i], -1);
        Q[X - a[i]].emplace_back(a[i], 1);
    }
    for (int i = 1; i <= m; i++) {
        M[b[i]].push_back(X - d[i] + 1);
    }
    for (int i = 0; i < X; i++) {
        for (int d : M[i]) add(d);
        for (auto p : Q[i]) ans += p.second * sum(p.first);
    }
    printf("%lld\n", ans);
    return 0;
}
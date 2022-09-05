#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, p[maxn], pos[maxn], L[maxn], R[maxn];
long long ans[maxn * 5];
array<int, 2> b[maxn * 5];
vector<array<int, 2>> M[maxn], Q[maxn];
vector<int> d[maxn];

struct BIT {
    long long c[maxn];
    void init() { memset(c, 0, sizeof(c)); }

    void add(int p, long long v) {
        for (; p <= n; p += p & -p) c[p] += v;
    }
    long long query(int p) {
        long long s = 0;
        for (; p; p -= p & -p) s += c[p];
        return s;
    }
} T[2];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), pos[p[i]] = i;
        for (int j = i; j <= n; j += i) d[j].push_back(i);
    }
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && p[st.back()] < p[i]) st.pop_back();
        L[i] = (st.empty() ? 0 : st.back()) + 1, st.push_back(i);
    }
    st.clear();
    for (int i = n; i; i--) {
        while (!st.empty() && p[st.back()] < p[i]) st.pop_back();
        R[i] = (st.empty() ? n + 1 : st.back()) - 1, st.push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &b[i][0], &b[i][1]);
        Q[b[i][0]].push_back({b[i][1], i});
    }
    for (int i = 1; i <= n; i++) {
        int mx = L[i] - 1, mn = R[i] + 1;
        if (i - L[i] < R[i] - i) {
            for (int x : d[p[i]]) if (1LL * x * x != p[i]) {
                int j = pos[x], k = pos[p[i] / x];
                if (j >= i && k >= i) mn = min(mn, max(j, k));
            }
            for (int j = i; j >= L[i]; j--) {
                if (!(p[i] % p[j])) {
                    int x = p[i] / p[j];
                    if (x != p[j]) {
                        if (pos[x] <= i) mx = max(mx, pos[x]);
                        else mn = min(mn, pos[x]);
                    }
                }
                if (mx >= j) M[j].push_back({i, R[i]});
                else M[j].push_back({mn, R[i]});
            }
        }
    }
    for (int i = n; i; i--) {
        for (auto &p : M[i]) {
            T[0].add(p[0], 1), T[0].add(p[1] + 1, -1);
            T[1].add(p[0], p[0]), T[1].add(p[1] + 1, -(p[1] + 1));
        }
        for (auto &p : Q[i]) {
            ans[p[1]] += (p[0] + 1) * T[0].query(p[0]) - T[1].query(p[0]);
        }
    }
    for (int i = 1; i <= n; i++) {
        M[i].clear(), Q[i].clear();
    }
    for (int i = 1; i <= q; i++) {
        Q[b[i][1]].push_back({b[i][0], i});
    }
    for (int i = 1; i <= n; i++) {
        int mx = L[i] - 1, mn = R[i] + 1;
        if (i - L[i] >= R[i] - i) {
            for (int x : d[p[i]]) if (1LL * x * x != p[i]) {
                int j = pos[x], k = pos[p[i] / x];
                if (j <= i && k <= i) mx = max(mx, min(j, k));
            }
            for (int j = i; j <= R[i]; j++) {
                if (!(p[i] % p[j])) {
                    int x = p[i] / p[j];
                    if (x != p[j]) {
                        if (pos[x] >= i) mn = min(mn, pos[x]);
                        else mx = max(mx, pos[x]);
                    }
                }
                if (mn <= j) M[j].push_back({L[i], i});
                else M[j].push_back({L[i], mx});
            }
        }
    }
    T[0].init(), T[1].init();
    for (int i = 1; i <= n; i++) {
        for (auto &p : M[i]) {
            p[0] = n - p[0] + 1, p[1] = n - p[1] + 1, swap(p[0], p[1]);
            T[0].add(p[0], 1), T[0].add(p[1] + 1, -1);
            T[1].add(p[0], p[0]), T[1].add(p[1] + 1, -(p[1] + 1));
        }
        for (auto &p : Q[i]) {
            p[0] = n - p[0] + 1;
            ans[p[1]] += (p[0] + 1) * T[0].query(p[0]) - T[1].query(p[0]);
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
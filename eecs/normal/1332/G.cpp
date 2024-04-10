#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, a[maxn], L[maxn], R[maxn], mx[maxn << 2];
array<int, 3> mx3[maxn];
array<int, 4> mx4[maxn];
vector<int> S[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd(int k, int l, int r, int p, int v) {
    if (l == r) { mx[k] = v; return; }
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    mx[k] = max(mx[ls], mx[rs]);
}

int find(int k, int l, int r, int p, int v) {
    if (mx[k] < v) return 0;
    if (l == r) return l;
    int t = 0;
    if (mid < p) t = find(rs, mid + 1, r, p, v);
    if (!t) t = find(ls, l, mid, p, v);
    return t;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        L[i] = st.empty() ? 0 : st.back(), st.push_back(i);
    }
    st.clear();
    for (int i = n; i; i--) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        R[i] = st.empty() ? 0 : st.back(), st.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (L[i] && R[i]) mx3[R[i]] = max(mx3[R[i]], {L[i], i, R[i]});
    }
    st.clear();
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        L[i] = st.empty() ? 0 : st.back(), st.push_back(i);
    }
    st.clear();
    for (int i = n; i; i--) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        R[i] = st.empty() ? 0 : st.back(), st.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (L[i] && R[i]) mx3[R[i]] = max(mx3[R[i]], {L[i], i, R[i]});
    }
    auto solve = [&](bool flag) { // 3142 or 3412
        st.clear();
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
            L[i] = st.empty() ? 0 : st.back(), st.push_back(i);
        }
        st.clear();
        for (int i = n; i; i--) {
            while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
            R[i] = st.empty() ? 0 : st.back(), st.push_back(i);
        }
        // condition: x < y, a_x >= a_y, R_x < y and L_y > x
        memset(mx, 0, sizeof(mx));
        for (int i = 1; i <= n; i++) {
            S[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            if (R[i]) S[R[i] + 1].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j : S[i]) upd(1, 1, n, j, a[j]);
            if (!L[i]) continue;
            int j = find(1, 1, n, L[i] - 1, a[i]);
            if (!j) continue;
            if (!flag) mx4[i] = max(mx4[i], {j, R[j], L[i], i});
            else mx4[n - j + 1] = max(mx4[n - j + 1], {n - i + 1, n - L[i] + 1, n - R[j] + 1, n - j + 1});
        }
    };
    solve(0);
    reverse(a + 1, a + n + 1), solve(1);
    for (int i = 1; i <= n; i++) {
        mx3[i] = max(mx3[i], mx3[i - 1]);
        sort(mx4[i].begin(), mx4[i].end());
        mx4[i] = max(mx4[i], mx4[i - 1]);
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (mx4[r][0] >= l) {
            printf("4\n%d %d %d %d\n", mx4[r][0], mx4[r][1], mx4[r][2], mx4[r][3]);
        } else if (mx3[r][0] >= l) {
            printf("3\n%d %d %d\n", mx3[r][0], mx3[r][1], mx3[r][2]);
        } else {
            puts("0");
        }
    }
    return 0;
}
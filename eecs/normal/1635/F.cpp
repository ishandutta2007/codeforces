#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, q, x[maxn], w[maxn], ql[maxn], qr[maxn];
ll ans[maxn], c[maxn];
vector<int> cand[maxn];
vector<array<int, 2>> Q[maxn];

void upd(int p, ll v) {
    for (; p; p -= p & -p) c[p] = min(c[p], v);
}

ll query(int p) {
    ll mn = LLONG_MAX;
    for (; p <= n; p += p & -p) mn = min(mn, c[p]);
    return mn;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &w[i]);
        if (i < n) cand[i + 1].push_back(i);
    }
    for (int i = 1, l, r; i <= q; i++) {
        scanf("%d %d", &l, &r);
        Q[r].push_back({l, i});
    }
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && w[st.back()] > w[i]) st.pop_back();
        if (!st.empty()) cand[i].push_back(st.back());
        st.push_back(i);
    }
    st.clear();
    for (int i = n; i; i--) {
        while (!st.empty() && w[st.back()] > w[i]) st.pop_back();
        if (!st.empty()) cand[st.back()].push_back(i);
        st.push_back(i);
    }
    memset(c, 0x3f, sizeof(c));
    for (int i = 1; i <= n; i++) {
        for (int j : cand[i]) {
            upd(j, 1LL * (x[i] - x[j]) * (w[i] + w[j]));
        }
        for (auto &p : Q[i]) {
            ans[p[1]] = query(p[0]);
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
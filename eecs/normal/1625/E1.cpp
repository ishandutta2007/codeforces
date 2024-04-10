#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, q, pre[maxn], nxt[maxn];
char s[maxn];
long long ans[maxn];
vector<int> V[maxn * 2];

int main() {
    scanf("%d %d %s", &n, &q, s + 1);
    pre[0] = n, V[n].push_back(0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
        if (i < n && s[i + 1] == '(') V[pre[i]].push_back(i);
    }
    vector<int> st;
    for (int i = n; ~i; i--) {
        while (!st.empty() && pre[i] <= pre[st.back()]) st.pop_back();
        nxt[i] = st.empty() ? n + 1 : st.back(), st.push_back(i);
    }
    for (int i = 0; i <= 2 * n; i++) if (!V[i].empty()) {
        for (int l = 0, r; l < V[i].size(); l = r) {
            for (r = l; r < V[i].size() && nxt[V[i][l]] > V[i][r]; r++);
            long long t = 1LL * (r - l) * (r - l + 1) / 2;
            ans[V[i][l] + 1] += t;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i - 1];
    }
    while (q--) {
        int l, r;
        scanf("%*d %d %d", &l, &r);
        long long sum = ans[r] - ans[l];
        auto p1 = lower_bound(V[pre[r]].begin(), V[pre[r]].end(), l - 1);
        auto p2 = lower_bound(V[pre[r]].begin(), V[pre[r]].end(), r);
        int k = p2 - p1;
        sum += 1LL * k * (k + 1) / 2;
        printf("%lld\n", sum);
    }
    return 0;
}
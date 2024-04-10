#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, mn, ans, id[maxn];
ll t[maxn], w[maxn];
priority_queue<ll, vector<ll>, greater<ll>> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &t[i], &w[i]);
        if (i > 1 && t[i] > t[1]) mn++, ans++;
        if (i > 1) id[i] = i;
    }
    sort(id + 2, id + n + 1, [&](int x, int y) { return t[x] > t[y]; });
    int pos = 2;
    while (pos <= n && t[id[pos]] > t[1]) {
        Q.push(w[id[pos]] - t[id[pos]] + 1), pos++;
    }
    while (!Q.empty()) {
        ll v = Q.top(); Q.pop();
        if (t[1] < v) break;
        t[1] -= v;
        while (pos <= n && t[id[pos]] > t[1]) {
            Q.push(w[id[pos]] - t[id[pos]] + 1), pos++;
        }
        mn = min(mn, (int)Q.size());
    }
    printf("%d\n", mn + 1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
multiset < ll > qwq;
int dfs(ll x) {
    auto ite = qwq.find(x);
    if (ite != qwq.end()) return qwq.erase(ite), 0;
    if (x == 1) return 1;
    if (dfs(x / 2)) return 1;
    if (dfs((x + 1) / 2)) return 1;
    return 0;
}
void rmain() {
    scanf("%d", &n);
    ll sum = 0;
    qwq.clear();
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        qwq.insert(x);
        sum += x;
    }
    if (dfs(sum)) puts("NO");
    else puts("YES");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a, b, c, ans;
multiset<int> S;

int main() {
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t), S.insert(t);
        if (t > a + b + c) printf("-1\n"), exit(0);
    }
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    auto F = [&](int x) {
        auto it = S.upper_bound(x);
        if (it != S.begin()) S.erase(--it);
    };
    while (!S.empty() && *S.rbegin() > b + c) F(a + b + c), ans++;
    while (!S.empty() && *S.rbegin() > a + c) F(b + c), F(a), ans++;
    while (!S.empty() && *S.rbegin() > max(a + b, c)) F(a + c), F(b), ans++;
    while (!S.empty() && *S.rbegin() > c) F(a + b), F(c), ans++;
    while (!S.empty()) {
        F(c), ans++;
        if (S.empty() || *S.begin() > a) F(a + b);
        else F(a), F(b);
    }
    printf("%d\n", ans);
    return 0;
}
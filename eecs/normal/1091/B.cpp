#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, x[maxn], y[maxn], a[maxn], b[maxn];
map<pair<int, int>, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[{x[i] + a[j], y[i] + b[j]}]++;
        }
    }
    for (auto p : mp) if (p.second == n) {
        printf("%d %d\n", p.first.first, p.first.second), exit(0);
    }
    assert(0);
    return 0;
}
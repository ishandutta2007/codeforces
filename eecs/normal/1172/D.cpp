#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, a[maxn], b[maxn];
vector<array<int, 4>> ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) if (a[i] ^ i || b[i] ^ i) {
        int pa, pb;
        for (int j = i; j <= n; j++) {
            if (a[j] == i) pa = j;
            if (b[j] == i) pb = j;
        }
        ans.push_back({i, pb, pa, i});
        swap(a[i], a[pa]), swap(b[i], b[pb]);
    }
    printf("%d\n", ans.size());
    for (auto &p : ans) {
        printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
    }
    return 0;
}
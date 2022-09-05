#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> P;
int n, zero;
P a[1010];
vector<P> ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][0]), a[i][1] = i;
    }
    sort(a + 1, a + n + 1, greater<>());
    if (!a[2][0]) puts("-1"), exit(0);
    auto op = [&](P &A, P &B) {
        ans.push_back({A[1], B[1]});
        B[0] -= A[0], A[0] *= 2;
    };
    while (a[3][0]) {
        int v = a[2][0] / a[3][0];
        for (int i = 1; i <= v; i <<= 1) op(a[3], i & v ? a[2] : a[1]);
        sort(a + 1, a + n + 1, greater<>());
    }
    printf("%d\n", ans.size());
    for (auto &p : ans) {
        printf("%d %d\n", p[0], p[1]);
    }
    return 0;
}
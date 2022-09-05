#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n;
map<int, int> mpx, mpy;
map<pair<int, int>, int> mpxy;

int main() {
    scanf("%d", &n);
    long long ans = 0;
    for (int _ = 1, x, y; _ <= n; _++) {
        scanf("%d %d", &x, &y);
        ans += mpx[x] + mpy[y] - mpxy[{x, y}];
        mpx[x]++, mpy[y]++, mpxy[{x, y}]++;
    }
    printf("%lld\n", ans);
    return 0;
}
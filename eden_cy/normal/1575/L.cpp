#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 4e5 + 10;
namespace Seg {
    int f[N << 1];
    inline void Init() {
        for (int i = 0; i < N << 1; ++i) f[i] = -1e9;
    }
    inline void Update(int x, int y) {
        for (int i = N + x; i; i >>= 1) f[i] = max(f[i], y);
    }
    inline int Ask(int x, int y) {
        int ans = -1e9;
        for (int l = N + x - 1, r = N + y + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) ans = max(ans, f[l ^ 1]);
            if ( r & 1) ans = max(ans, f[r ^ 1]);
        }
        return ans;
    }
}
int n;
pii p[N];
int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        p[i] = pii(i - x, x);
    }
    sort(p + 1, p + n + 1);
    Seg::Init();
    Seg::Update(0, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (p[i].first >= 0) {
        int f = Seg::Ask(0, p[i].second - 1) + 1;
        ans = max(ans, f);
        // printf("%d %d %d\n", p[i].first, p[i].second, f);
        Seg::Update(p[i].second, f);
    }
    printf("%d\n", ans);
    return 0;
}
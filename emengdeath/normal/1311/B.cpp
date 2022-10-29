#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int a[N], b[N], c[N];
int fa[N];
int getfa(int x) {
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; i ++)
            scanf("%d", &b[i]);
        sort(b+1, b+m+1);
        int l = 1;
        while (l <= m ) {
            int r = l;
            while (r < m && b[r + 1] == b[r] + 1) r ++;
            sort(a +b[l], a + b[r] + 2);
            l = r +1;
        }
        bool sig = 1;
        for (int i = 2; i <= n; i ++)
            sig &= a[i] >= a[i - 1];
        sig?puts("YES"):puts("NO");
    }
    return 0;
}
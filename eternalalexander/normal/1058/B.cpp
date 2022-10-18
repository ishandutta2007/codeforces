#include <cstdio>

int main() {
    int n, d, m, x, y;
    scanf("%d %d %d", &n, &d, &m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d", &x, &y);
        if (x+y>=d&&x+y<=n*2-d&&y-x<=d&&y-x>=-d) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
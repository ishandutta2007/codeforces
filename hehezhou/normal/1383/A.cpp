#include <bits/stdc++.h>
using namespace std;
int fa[100];
inline int gf(int a) {
    return fa[a] == a ? a : fa[a] = gf(fa[a]);
}
char A[100010], B[100010];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s%s", A + 1, B + 1);
        int ans = 0;
        for (int i = 0; i <= 20; i++) fa[i] = i;
        for (int i = 1; i <= n; i++) {
            if (A[i] > B[i]) {
                puts("-1");
                goto gototag;
            }
            if (gf(A[i] - 'a') == gf(B[i] - 'a')) continue;
            fa[gf(A[i] - 'a')] = B[i] - 'a';
            ans++;
        }
        printf("%d\n", ans);
        gototag:;
    }
}
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 201;
int n, m, k;
struct node{
    int sx, sy, tx, ty;
}a[N];
char s[1000000];
int tot;
void p(int x, char c){
    while (x --) s[++tot] = c;
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i ++) {
        scanf("%d %d", &a[i].sx, &a[i].sy);
    }
    for (int i = 1; i <= k; i ++)
        scanf("%d %d", &a[i].tx, &a[i].ty);
    p(n - 1, 'U');
    p(m - 1, 'L');
    for (int i =1; i <= n; i ++)
        if (i & 1) {
            p(m - 1, 'R');
            if (i != n)
                p(1, 'D');
        } else
        {
            p(m - 1, 'L');
            if (i != n)
                p(1, 'D');
        }
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i ++)
        printf("%c", s[i]);
    return 0;
}
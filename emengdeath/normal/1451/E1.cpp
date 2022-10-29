#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1<< 16;
int n;
int ask(int type, int x, int y) {
    switch (type) {
        case 0:
            printf("AND %d %d\n", x, y);
            break;
        case 1:
            printf("XOR %d %d\n", x, y);
            break;
    }
    fflush(stdout);
    scanf("%d", &x);
    return x;
}
int a[N + 10], loc[N + 10];
int ans;
void output() {
    printf("! %d", ans);
    for (int i = 2; i <= n;i ++)
        printf(" %d", ans ^ a[i]);
    fflush(stdout);
    exit(0);
}
int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++)
        a[i] = ask(1, 1, i);
    for (int i = 2; i <= n; i ++) {
        if (!a[i]) {
            ans = ask(0, 1, i);
            output();
        }
        if (loc[n - 1 - a[i]]) {
            ans = (ask(0, 1, loc[n - 1 - a[i]]) | ask(0, 1, i));
            output();
        }
        if (loc[a[i]]) {
            ans = (ask(0, loc[a[i]], i) ^ a[i]);
            output();
        }
        loc[a[i]] = i;
    }
    return 0;
}
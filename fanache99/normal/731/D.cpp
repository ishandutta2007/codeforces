#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

int a[1 + MAXN], b[1 + MAXN];
int v[1 + MAXN];

void Try(int la, int lb, int c) {
    int i = 1;
    while (i <= la && i <= lb && a[i] == b[i])
        i++;
    if (i > la) {
        v[0]++;
        return;
    }
    if (i > lb) {
        printf("-1\n");
        exit(0);
    }
    int x = a[i], y = b[i];
    if (x < y) {
        v[0]++;
        v[c - y + 1]--;
        if (x != 1)
            v[c - x + 1]++;
    }
    else {
        v[c - x + 1]++;
        v[c - y + 1]--;
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, c, la, lb;
    scanf("%d%d", &n, &c);
    scanf("%d", &la);
    for (int i = 1; i <= la; i++)
        scanf("%d", &a[i]);
    for (int j = 2; j <= n; j++) {
        scanf("%d", &lb);
        for (int i = 1; i <= lb; i++)
            scanf("%d", &b[i]);
        Try(la, lb, c);
        la = lb;
        for (int i = 1; i <= la; i++)
            a[i] = b[i];
    }
    int x = 0;
    for (int i = 0; i < c; i++) {
        x += v[i];
        if (x == n - 1) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
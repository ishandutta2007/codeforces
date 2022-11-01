#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

int n, a[MN], x, y;
char s[MN]; string str;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int ok(int sz) {
    int X = 0, Y = 0, ret = 0;
    for(int i = 0; i < n; i++) {
        X += dx[a[i]];
        Y += dy[a[i]];
    }

    for(int i = 0; i < sz; i++) {
        X -= dx[a[i]];
        Y -= dy[a[i]];
    }

    for(int i = sz; i < n; i++) {
        if(abs(X - x) + abs(Y - y) <= sz) ret = 1;

        X += dx[a[i-sz]];
        Y += dy[a[i-sz]];

        X -= dx[a[i]];
        Y -= dy[a[i]];
    }
    if(abs(X - x) + abs(Y - y) <= sz) ret = 1;
    return ret;
}

int main() {
    scanf("%d %s", &n, s); str = s;
    scanf("%d %d", &x, &y);

    if((abs(x + y) % 2) != (n % 2)) {
        printf("-1\n");
        return 0;
    }

    for(int i = 0; i < n; i++) {
        if(str[i] == 'U') a[i] = 0;
        if(str[i] == 'R') a[i] = 1;
        if(str[i] == 'D') a[i] = 2;
        if(str[i] == 'L') a[i] = 3;
    }

    int l = 0, r = n+1, m;
    while(l < r) {
        m = (l + r) / 2;
        if(ok(m)) r = m;
        else l = m + 1;
    }

    if(l <= n) printf("%d\n", l);
    else puts("-1");
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, a[1010], p[1010], color[1010];

int calc(int x) {
    if(color[x] == 2) return p[x];
    if(color[x] == 1) {
        p[x] = x;
        for(int y = a[x]; y != x; y = a[y]) {
            p[y] = y;
        }
        return p[x];
    }
    color[x] = 1;
    int ret = calc(a[x]);
    color[x] = 2;
    if(p[x]) return x;
    return p[x] = ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(!p[i]) calc(i);
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}
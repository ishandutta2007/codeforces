#include <bits/stdc++.h>
#define MN 300030

using namespace std;

int rmq[MN][20], gcd[MN][20], a[MN], bits[MN];
int n;

void build() {
    for(int i = 0; i < n; i++)
        rmq[i][0] = gcd[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 0; i + (1<<j) <= n; i++) {
            rmq[i][j] =   min(rmq[i][j-1], rmq[i+(1<<j-1)][j-1]);
            gcd[i][j] = __gcd(gcd[i][j-1], gcd[i+(1<<j-1)][j-1]);
        }

    for(int i = 1; i <= n; i++)
        bits[i] = 31 - __builtin_clz(i);
}

int querymin(int a, int b) {
    if(a > b) swap(a, b);
    int lg = bits[b - a + 1];
    return min(rmq[a][lg], rmq[b-(1<<lg)+1][lg]);
}

int querygcd(int a, int b) {
    if(a > b) swap(a, b);
    int lg = bits[b - a + 1];
    return __gcd(gcd[a][lg], gcd[b-(1<<lg)+1][lg]);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    build();

    int l = 0, r = n - 1, m;
    vector<int> pos;
    while(l < r) {
        m = (l + r + 1) / 2;
        int flag = 0;

        for(int i = 0, j = i + m; j < n; i++, j++) {
            int mini = querymin(i, j);
            int g    = querygcd(i, j);
            if(g == mini) flag = 1;
        }

        if(flag) l = m;
        else r = m - 1;
    }

    for(int i = 0, j = i + l; j < n; i++, j++) {
        int mini = querymin(i, j);
        int g    = querygcd(i, j);
        if(g == mini) pos.push_back(i + 1);
    }

    printf("%d %d\n", pos.size(), l);
    for(int x : pos) {
        printf("%d ", x);
    }

    return 0;
}
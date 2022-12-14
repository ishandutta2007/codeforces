#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

char g[1100][1100];
int c[1000];

void add_edge(int x, int y){
    g[x][y] = 'Y';
    g[y][x] = 'Y';
}

int main(){
    int k;
    scanf("%d", &k);
    if (k == 1){
        puts("2");
        puts("NY");
        puts("YN");
        return 0;
    }
    int n = 2;
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j)
            g[i][j] = 'N';
    int tot = 0;
    memset(c, 0, sizeof(c));
    while (k){
        c[tot++] = k % 3;
        k /= 3;
    }
    while (c[tot] == 0) --tot;
    for (int i = tot; i >= 0; --i)
        if (c[i] != 0){
            int u = 1;
            for (int j = 0; j < tot - i; ++j){
                add_edge(u, ++n);
                u = n;
                add_edge(u, ++n);
                u = n;
            }
            for (int j = 0; j < i; ++j){
                add_edge(u, ++n);
                add_edge(u, ++n);
                add_edge(u, ++n);
                add_edge(n, n + 1);
                add_edge(n - 1, n + 1);
                add_edge(n - 2, n + 1);
                ++n;
                u = n;
            }
            if (c[i] == 1){
                add_edge(u, ++n);
                add_edge(n, 2);
            } else {
                add_edge(u, ++n);
                add_edge(u, ++n);
                add_edge(n, 2);
                add_edge(n - 1, 2);
            }
        }
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            putchar(g[i][j]);
        putchar('\n');
    }
    return 0;
}
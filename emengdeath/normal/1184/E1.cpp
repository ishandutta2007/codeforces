#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N = 1e5 + 1;
int fa[N];
int a[N * 10][3], b[N * 10];
int n, m, u, v;
int getfa(int x) {return fa[x] == x? x: fa[x] = getfa(fa[x]);}
int main() {
    scanf("%d %d", &n, &m);
    int x;
    scanf("%d %d %d", &u, &v, &x);
    m --;
    for (int i = 1; i <= n ;  i++)fa[i] = i;
    for(int i = 1; i<= m ;  i ++)
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]), b[i] = i;
    sort(b +1, b + m + 1, [](int x ,int y) {return a[x][2] < a[y][2];});
    for (int i = 1; i <= m ; i ++){
        int x = getfa(a[b[i]][0]);
        int y = getfa(a[b[i]][1]);
        int fau = getfa(u);
        int fav = getfa(v);
        if (x > y) swap(x, y);
        if (fau > fav) swap(fau, fav);
        if (fau == x && fav == y) {
            printf("%d\n", a[b[i]][2]);
            return 0;
        }
        if (x != y) {
            fa[x] = y;
        }
    }
    printf("1000000000");
    return 0;
}
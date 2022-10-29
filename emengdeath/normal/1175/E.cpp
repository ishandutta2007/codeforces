#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 5e5 + 1;
int f[N][20];
int n, m;
priority_queue<pair<int, int> > h;
struct node{
    int l, r;
}a[N];
int main() {
    scanf("%d %d", &n, &m);
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n ; i ++)
        scanf("%d %d", &a[i].l, &a[i].r);
    sort(a+1,a+n+1,[](node &a, node &b) {return a.r > b.r;});
    int l = 1;
    for (int i = 5e5; i >= 0; i--){
        while (l <= n && a[l].r >= i) {
            h.push(make_pair(a[l].r, l));
            l ++;
        }
        while (!h.empty() && a[h.top().second].l > i) {
            h.pop();
        }
        if (!h.empty() && h.top().first != i)
            f[i][0] = h.top().first;
    }
    for (int i = 0; i < 19; i ++)
        for (int j = 0; j <= 5e5; j ++)
            if (f[j][i] != -1 && f[f[j][i]][i] != -1 )
            f[j][i + 1] = f[f[j][i]][i];
    while (m -- ){
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = 0;
        for (int i = 19; i >= 0; i --)
            if (f[l][i] != -1 && f[l][i] < r)
                l = f[l][i], ans += 1 << i;
        if (f[l][0] != -1) {
            printf("%d\n", ans + 1);
        }else
            printf("-1\n");
    }
    return 0;
}
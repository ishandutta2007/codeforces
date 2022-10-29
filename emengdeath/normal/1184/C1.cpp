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
struct point{
    int x, y;
}a[1000], mn, mx;
int n;
bool check(int x){
    if (x != 1) mn = mx = a[1];
    else
        mn = mx = a[2];
    for (int i = 1; i <= n ; i ++)
        if (i != x) {
            mn.x = min(mn.x, a[i].x);
            mn.y = min(mn.y, a[i].y);
            mx.x = max(mx.x, a[i].x);
            mx.y = max(mx.y, a[i].y);
        }
    int sum = 0;
    for (int i = 1; i <= n ; i ++)
        if (i != x) {
            if (a[i].x == mn.x || a[i].x == mx.x || a[i].y == mn.y || a[i].y == mx.y) sum ++;
        }
    return sum == n - 1 && mx.x - mn.x == mx.y - mn.y;
}
int main() {
    scanf("%d", &n);
    n = n * 4 + 1;
    for (int i = 1; i <= n ; i ++)
        scanf("%d %d", &a[i].x,&a[i].y);
    for (int i = 1; i <= n ;  i++)
        if (check(i)){
            printf("%d %d\n", a[i].x, a[i].y);
            return 0;
        }
    return 0;
}
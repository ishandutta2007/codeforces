#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
const int N = 4e6 + 1;
short f[N][21];
int a[N];
void update(int x, int d) {
    if (d > 20 || f[x][d] > 1) return;
    f[x][d] ++;
    update(x, d + 1);
    if (x & (1 << d))
        update(x - (1 << d), d);
}
int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n ; i ++){
        scanf("%d", &a[i]);
    }
    for (int i = n ; i >= 1; i --) {
        int v = 0, x = 0;
        if (n - i + 1 >= 3)
        for (int j = 20; j >=0; j --)
            if ((a[i] >> j) & 1)
                v += 1 << j;
            else
                if (f[x  + (1 << j)][20] > 1)
                    v += 1 << j, x += (1 << j);
        update(a[i], 0);
        ans =max(ans, v);
    }
    printf("%d\n", ans);
    return 0;
}
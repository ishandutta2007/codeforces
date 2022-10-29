#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
int n;
int all = 0;
int a[10000], d[10000];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &a[i]), all += a[i];
    }
    for (int i = 1; i < n ; i ++)
        d[i] = i + 1;
    sort(d + 1, d + n , [](int x, int y) {return a[x] < a[y];});
    int ans = a[1];
    int l = 0;
    while (l + 1 < n && a[d[l + 1]]  <= a[1] / 2) ans += a[d[++ l]];
    if (ans * 2 > all) {
        printf("%d\n", l + 1);
        printf("1");
        for (int i = 1; i <= l ; i ++)
            printf(" %d", d[i]);
        printf("\n");
    }else {
        printf("0\n");
    }
    return 0;
}
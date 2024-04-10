#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
int t[101];
int n, m, all;
int main()
{
    scanf("%d %d",&n, &m);
    for (int i = 1; i <= n ; i ++) {
        int x;
        scanf("%d", &x);
        all += x;
        int y = all, sum = 0;
        for (int j = 100; j >= 1 && y > m; j -- ) {
            int sum1 = min((y - m) / j + ((y - m) % j > 0), t[j]);
            sum += sum1;
            y -= sum1 * j;
        }
        t[x] ++;
        printf("%d ", sum);
    }
    return 0;
}
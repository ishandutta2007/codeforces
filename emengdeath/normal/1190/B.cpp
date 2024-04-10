#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;
int m, n;
int a[N];
int main()
{
    long long x = 0;
    bool sig = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {

        scanf("%d", &a[i]);
        if (a[i]) sig = 0;
    }
    if (sig) {
        printf("cslnb\n");
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i ++)
        if (a[i] == a[i + 1]) {
            if (i > 1&& a[i - 1] == a[i] - 1)x ++;
            x ++;
        }
    if (x > 1) {
        printf("cslnb\n");
        return 0;
    }
    x = 0;
    for (int i = 1; i <= n ; i ++)
        if (a[i] < i - 1) {
            printf("cslnb\n");
            return 0;
        } else
            x += (a[i] - (i - 1));
    if (!(x & 1))
        printf("cslnb");
    else
        printf("sjfnb");
    return 0;
}
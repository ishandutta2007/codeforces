#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
long long ans;
int main()
{
    int n;
    scanf("%d", &n);
    ans = 1;
    if (n & 1)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n / 2; i ++)
        ans *= 2;
    printf("%lld\n", ans);
    return 0;
}
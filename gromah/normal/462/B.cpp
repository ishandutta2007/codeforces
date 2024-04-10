#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, F[30];
long long ans = 0;

int main()
{
    scanf("%d%d", &n, &k);
    char ch = getchar();
    for (int i = 1; i <= n; i ++)
    {
        while (ch > 'Z' || ch < 'A')
            ch = getchar();
        F[ch - 'A'] ++;
        ch = getchar();
    }
    sort(F, F + 26);
    for (int i = 25; i >= 0 && k; i --)
    {
        int t = min(F[i], k);
        ans += (long long) t * t;
        k -= t;
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (abs(n - m) < k)
    {
        printf("%d", max(n, m) * 2 + (((k - abs(n - m)) / 2) * 2));
    }
    else
    {
        printf("%d", min(n, m) * 2 + k * 2);
    }
    return 0;
}
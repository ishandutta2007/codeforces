#include <bits/stdc++.h>
using namespace std;

int a, b, cnt = 1, rj = 0;

int main()
{
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    while (a < b)
    {
        a++; b--;
        rj += cnt * 2;
        cnt++;
    }
    if (a > b) printf("%d", rj - cnt + 1);
    else printf("%d", rj);
    return 0;
}
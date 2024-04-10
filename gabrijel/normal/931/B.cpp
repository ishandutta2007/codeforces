#include <bits/stdc++.h>
using namespace std;

int n, a, b, rj = 0;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    a += n - 1;
    b += n - 1;
    while (a != b)
    {
        rj++;
        a /= 2; b /= 2;
    }
    if (a == 1) printf("Final!");
    else printf("%d", rj);
    return 0;
}
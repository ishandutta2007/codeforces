#include <bits/stdc++.h>
using namespace std;

int n, rj = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        if ((n - i) % i == 0) rj++;
    }
    printf("%d",  rj);
    return 0;
}
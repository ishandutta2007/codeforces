#include <bits/stdc++.h>
using namespace std;

int n, rj = 0;
int dub [100100];
int kolkonadub [100100];

int main()
{
    int x;
    scanf("%d", &n);
    dub [0] = 0;
    kolkonadub [0] = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        x--;
        dub [i] = dub [x] + 1;
        kolkonadub [dub [i]]++;
    }
    for (int i = 0; i < 100050; i++)
    {
        if (kolkonadub [i] & 1) rj++;
    }
    printf("%d", rj);
    return 0;
}
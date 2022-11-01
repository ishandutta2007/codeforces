#include <bits/stdc++.h>
using namespace std;

int n, s, f, raz, maxi, koji, potrj;
int a [100100];
int suma [200100];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a [i]);
    }
    scanf("%d%d", &s, &f);
    raz = f - s;
    suma [0] = a [0];
    for (int i = 1; i < 2 * n + 1; i++)
    {
        suma [i] = suma [i - 1] + a [i % n];
    }
    maxi = suma [raz - 1];
    koji = 0;
    potrj = s;
    for (int i = raz; i < 2 * n + 1; i++)
    {
        if (maxi <= suma [i] - suma [i - raz])
        {
            if (maxi < suma [i] - suma [i - raz])
            {
                maxi = suma [i] - suma [i - raz];
                koji = (i - raz + 1) % n;
                if (s > koji)
                {
                    potrj = s - koji;
                }
                else
                {
                    potrj = n - koji + s;
                }
            }
            else
            {
                koji = (i - raz + 1) % n;
                if (s > koji)
                {
                    if (potrj > s - koji) potrj = s - koji;
                }
                else
                {
                    if (potrj > n - koji + s) potrj = n - koji + s;
                }
            }
        }
    }
    printf("%d", potrj);
    return 0;
}
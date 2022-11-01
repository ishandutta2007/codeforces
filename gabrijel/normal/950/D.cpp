#include <bits/stdc++.h>
using namespace std;

long long int n, x;
long long int l, r, mid;
int q;

long long int rek(long long int lg, long long int rg, long long int poz)
{
    if (lg == rg)
    {
        if (poz % 2 == 0)
        {
            return (long long) poz / 2 + 1;
        }
        else
        {
            return (long long) (poz + 1) / 2 + 1;
        }
    }
    if (poz % 2 == 0)
    {
        return (long long) poz / 2 + 1;
    }
    mid = lg + (rg - lg) / 2 + 1;
    return rek(mid, rg, (poz - lg) / 2 + mid);
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        x--;
        l = 0; r = n * 2 - 2;
        cout << rek(l, r, x) << endl;
    }
    return 0;
}
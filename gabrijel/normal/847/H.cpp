#include <iostream>
using namespace std;

int main()
{
    long long int a [100005];
    long long int n, rj = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a [i];
    }
    int lg = 0, dg = n - 1;
    while (a [lg] < a [lg + 1])
    {
        if (lg == dg)
        {
            cout << rj;
            return 0;
        }
        lg++;
    }
    while (a [dg] < a [dg - 1])
    {
        if (lg == dg)
        {
            cout << rj;
            return 0;
        }
        dg--;
    }
    while (lg != dg)
    {
        /*int x = a [lg] - a [lg + 1] + 1;
        int y = a [dg] - a [dg - 1] + 1;
        if (x < y)
        {
            a [lg + 1] += x;
            rj += x;
        }
        else
        {
            a [dg - 1] += y;
            rj += y;
        }*/
        if (a [lg] < a [dg])
        {
            rj += a [lg] - a [lg + 1] + 1;
            a [lg + 1] += a [lg] - a [lg + 1] + 1;
        }
        else
        {
            rj += a [dg] - a [dg - 1] + 1;
            a [dg - 1] += a [dg] - a [dg - 1] + 1;
        }
        while (a [lg] < a [lg + 1])
        {
            if (lg == dg)
            {
            cout << rj;
            return 0;
            }
            lg++;
        }
        while (a [dg] < a [dg - 1])
        {
            if (lg == dg)
            {
            cout << rj;
            return 0;
            }
            dg--;
        }
    }
    cout << rj;
    return 0;
}
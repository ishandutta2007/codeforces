#include <iostream>
#include <cstdlib>

using namespace std;

int n, me = 0, a[200000], e[2000000] = {}, l[2000000] = {}, f[2000000] = {}, al, ar, aq;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        e[a[i]]++;
        l[a[i]] = i;
        if (e[a[i]] == 1) f[a[i]] = i;
    }
    for (int i = 0; i < 2000000; i++)
        if (e[i] > me) me = e[i];
    aq = n + n;
    for (int i = 0; i < 2000000; i++)
    {
        if (e[i] != me) continue;
        int q = l[i] - f[i] + 1;
        if (q < aq)
        {
            aq = q;
            al = f[i];
            ar = l[i];
        }
    }
    cout << al + 1 << " " << ar + 1;
}
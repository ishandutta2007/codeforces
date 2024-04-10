#include <bits/stdc++.h>
using namespace std;

int i, n, c, c2, n2;

int main()
{
    scanf ("%d\n", &n);
    n2 = n;
    for (i = 0; i < n; i ++)
    {
        scanf ("%c", &c);
        if (c == 'U' && c2 == 'R' || c == 'R' && c2 == 'U')
        {
            n2 --;
            c2 = 'D';
        }
        else
        {
            c2 = c;
        }
    }
    printf ("%d", n2);
    return 0;
}
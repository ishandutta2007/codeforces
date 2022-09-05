#include<bits/stdc++.h>

using namespace std;

int N, M, ap[(1 << 19) + 2];
char sir[30];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &M);
while (M --)
{
    char type;
    scanf ("%c ", &type);
    if (type == '+' || type == '-')
    {
        long long x;
        scanf ("%I64d\n", &x);
        long long msk = 0;
        for (int i=18; i>=0; i--)
        {
            int dig = x % 10;
            if (dig & 1) msk |= 1 << i;
            x /= 10;
        }
        if (type == '+') ap[msk] ++;
        else ap[msk] --;
        continue;
    }
    gets (sir + 1), N = strlen (sir + 1);
    int j = N, msk = 0;
    for (int i=18; i>=0; i--)
    {
        bool curr = 0;
        if (j >= 1) curr = sir[j] - '0', j --;
        if (curr) msk |= 1 << i;
    }
    printf ("%d\n", ap[msk]);
}

return 0;
}
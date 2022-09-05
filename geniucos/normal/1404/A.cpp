#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009;
char sir[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int N, K;
    scanf ("%d %d\n", &N, &K);
    scanf ("%s", sir + 1);
    bool ok = 1;
    for (int i=1; i<=K; i++)
    {
        int c0 = 0, c1 = 0;
        for (int j=i; j<=N; j+=K)
            if (sir[j] == '0') c0 ++;
            else
            if (sir[j] == '1') c1 ++;
        if (c0 > 0 && c1 > 0)
            ok = 0;
        if (c0 > 0 || c1 > 0)
        {
            int val = (c1 > 0);
            for (int j=i; j<=N; j+=K)
                sir[j] = '0' + val;
        }
    }
    int c0 = 0, c1 = 0;
    for (int i=1; i<=K; i++)
        if (sir[i] == '0') c0 ++;
        else c1 += (sir[i] == '1');
    ok &= (c0 <= K / 2 && c1 <= K / 2);
    if (ok) printf ("YES\n");
    else printf ("NO\n");
}

return 0;
}
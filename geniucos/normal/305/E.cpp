#include<bits/stdc++.h>

using namespace std;

int N, sg[5009], type[5009], frq[5009], ap[5009];
char sir[5009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
    type[i] = (sir[i - 1] == sir[i + 1] && i < N && i + 1);
for (int i=1; i<=N; i++)
    if (type[i])
    {
        int j = i;
        while (type[j])
            j ++;
        j --;
        frq[j - i + 1] ++;
        i = j;
    }
sg[0] = 0;
int ans = 0;
for (int i=1; i<=N; i++)
{
    for (int j=1; j<=i; j++)
    {
        int curr;
        if (j == 1 || j == i) curr = sg[max (i - 2, 0)];
        else curr = sg[j - 2] ^ sg[i - j - 1];
        ap[curr] = 1;
    }
    while (ap[sg[i]] == 1)
        sg[i] ++;
    ///take back
    for (int j=1; j<=i; j++)
    {
        int curr;
        if (j == 1 || j == i) curr = sg[max (i - 2, 0)];
        else curr = sg[j - 2] ^ sg[i - j - 1];
        ap[curr] = 0;
    }
    if (frq[i] & 1)
        ans ^= sg[i];
}
int ansPos = -1;
for (int i=1; i<=N; i++)
    if (type[i])
    {
        int j = i;
        while (type[j])
            j ++;
        j --;
        ///[i, j]
        int aux = ans ^ sg[j - i + 1];
        for (int k=i; k<=j; k++)
            if (aux ^ sg[max (k - i - 1, 0)] ^ sg[max (j - k - 1, 0)]) ;
            else
            if (ansPos == -1)
            {
                ansPos = k;
                break;
            }
        ///
        i = j;
    }
if (ans) printf ("First\n%d\n", ansPos);
else printf ("Second\n");
return 0;
}
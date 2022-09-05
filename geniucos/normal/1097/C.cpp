#include<bits/stdc++.h>

using namespace std;

int M, zr, N, b[1000009], m[1000009];
int ap1[1000009], ap2[1000009];
char sir[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%s\n", sir + 1);
    int L = strlen (sir + 1);
    for (int j=1; j<=L; j++)
    {
        if (sir[j] == '(') b[i] ++;
        else b[i] --;
        m[i] = min (m[i], b[i]);
    }
    if (b[i] == 0) zr += (m[i] >= 0);
    else
    if (b[i] > 0) ap1[b[i]] += (m[i] >= 0);
    else ap2[-b[i]] += (m[i] >= b[i]);
    M = max (M, b[i]), M = max (M, -b[i]);
}
int ans = zr / 2;
for (int i=1; i<=M; i++)
    ans += min (ap1[i], ap2[i]);
printf ("%d\n", ans);
return 0;
}
#include<bits/stdc++.h>

using namespace std;

int N, ap[3][3];
char a[100009], b[100009];
long long ans;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
scanf ("%s\n", a + 1);
scanf ("%s", b + 1);
for (int i=1; i<=N; i++)
    a[i] -= '0', b[i] -= '0',
    ap[a[i]][b[i]] ++;
for (int i=0; i<2; i++)
    for (int j=0; j<2; j++)
    {
        ///0i and 1j to 1i and 0j
        if (i != 1 || j != 1)
            ans += 1LL * ap[0][i] * ap[1][j];
    }
printf ("%I64d\n", ans);
return 0;
}
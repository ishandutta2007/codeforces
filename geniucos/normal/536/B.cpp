#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, L, ap[1000009], phi[1000009];
char sir[1000009], a[1000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);

gets (sir + 1);
L = strlen (sir + 1);

for (int i=1; i<=N; i++)
    a[i] = '?';

int maxi = 0;
while (M)
{
    M --;
    int pos, inceput;
    scanf ("%d", &inceput);
    pos = inceput + L - 1;
    ap[pos] = 1;
    if (pos > maxi)
    {
        int de_unde = maxi + 1;
        if (inceput > de_unde)
            de_unde = inceput;
        for (int i=de_unde; i<=pos; i++)
            a[i] = sir[i - inceput + 1];
        maxi = pos;
    }
}

int k = 0;
phi[1] = 0;
for (int i=2; i<=L; i++)
{
    while (k != 0 && sir[k+1] != sir[i])
        k = phi[k];
    if (sir[k+1] == sir[i])
        k ++;
    phi[i] = k;
}

k = 0;
for (int i=1; i<=N; i++)
{
    while (k != 0 && sir[k+1] != a[i])
        k = phi[k];

    if (sir[k+1] == a[i])
        k ++;

    if (k == L)
    {
        k = phi[k];
        ap[i] = 0;
    }

    if (ap[i])
    {
        printf ("0\n");
        return 0;
    }
}

int sol = 1, mod = 1000000007;
for (int i=1; i<=N; i++)
    if (a[i] == '?')
        sol = (1LL * sol * 26) % mod;

printf ("%d\n", sol);

return 0;
}
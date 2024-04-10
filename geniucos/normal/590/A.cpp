#include<cstdio>
#include<bitset>
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

int N, ans, a[500009], b[500009];

/*int N, ap[10009], nxt[10009], niv[10009], a[500009], b[500009];
vector < int > v[10009];

void Print (int msk)
{
    for (int i=0; i<N; i++)
        if (msk & (1 << i)) printf ("1");
        else printf ("0");
}

void df (int nod)
{
    ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    {
        if (ap[*it])
        {
            printf ("kkt de ciclu\n"), Print (*it), printf ("\n\n");
            return ;
        }
        niv[*it] = niv[nod] + 1;
        df (*it);
    }
}*/

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);

a[0] = a[1], a[N + 1] = a[N];
int maxi = 0;
for (int i=1; i<=N; i++)
    if (a[i] != a[i + 1] && a[i] == a[i-1])
    {
        int j = i;
        while (a[j] != a[j + 1] && j <= N) j++;
        if (j - i > maxi)
            maxi = j - i;
        for (int k=i; k<=j; k++)
        {
            if (k - i <= j - k) a[k] = a[i];
            else a[k] = a[j];
        }
        i = j;
    }
printf ("%d\n", maxi >> 1);
for (int i=1; i<=N; i++)
    printf ("%d ", a[i]);
printf ("\n");

/*while (1)
{
    b[1] = a[1], b[N] = a[N];
    for (int i=2; i<N; i++)
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 2;
    bool ok = 1;
    for (int i=1; i<=N; i++)
        if (b[i] != a[i]) ok = 0;
    if (ok)
    {
        printf ("%d\n", ans);
        for (int i=1; i<=N; i++)
            printf ("%d ", b[i]);
        printf ("\n");
        return 0;
    }
    ans ++;
    for (int i=1; i<=N; i++)
        a[i] = b[i];
    if (ans > 8) break;
}*/

return 0;
}

/*#include<cstdio>
#include<bitset>
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

int N, ap[1000009], nxt[1000009], niv[1000009], a[500009], b[500009];
vector < int > v[1000009];

void Print (int msk)
{
    for (int i=0; i<N; i++)
        if (msk & (1 << i)) printf ("1");
        else printf ("0");
}

void df (int nod)
{
    ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    {
        niv[*it] = niv[nod] + 1;
        df (*it);
    }
}

int main()
{
freopen ("input", "r", stdin);
freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<(1<<N); i++)
{
    for (int j=0; j<N; j++)
        a[j + 1] = ((i & (1 << j)) > 0);
    for (int j=2; j<N; j++)
        b[j] = (a[j - 1] + a[j] + a[j + 1]) / 2;
    b[1] = a[1], b[N] = a[N];
    int msk = 0;
    for (int j=1; j<=N; j++)
        if (b[j]) msk |= (1<<(j - 1));
    nxt[i] = msk;
    if (i != msk) v[msk].push_back (i);
    if (i == msk)
    {
        printf ("stabil : "), Print (i);
        printf ("\n");
    }
   // Print (i), printf ("->"), Print (msk), printf ("\n");
}
for (int i=0; i < (1 << N); i++)
    if (ap[i] == 0)
        df (i);
int maxi = 0;
for (int i=0; i<(1<<N); i++)
{
    int j = i, ans = 0;
    while (nxt[j] != j) j = nxt[j], ans ++;
    if (ans != 0) Print (i), printf (" -> %d (", ans), Print (j), printf (")\n");
    if (ans > maxi) maxi = ans;
}
printf ("%d\n", maxi);
//for (int i=0; i<(1<<N); i++)
  //  Print (i), printf (" -> %d\n", niv[i]);

return 0;
}*/
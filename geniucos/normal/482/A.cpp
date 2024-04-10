#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int j, n, K, ap[100009], a[100009];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
scanf ("%d%d", &n, &K);
a[1] = K+1;
a[2] = 1;
ap[1] = ap[K+1] = 1;
for (int i=3; i<=n; i++)
{
    if (i%2 == 1) a[i] = a[i-2] - 1;
    else a[i] = a[i-2] + 1;
    if (ap[a[i]])
    {
        j = i - 1;
        break;
    }
    ap[a[i]] = 1;
}
if (j == 0)
    j = n;
for (int i=n; i>=K+2; i--)
    printf ("%d ", i);
for (int i=1; i<=j; i++)
    printf ("%d ",a[i]);
printf ("\n");
return 0;
}
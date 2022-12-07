#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, j, cnt, out, alt;
int t [200001];

int main ()
{
    scanf ("%d",&n);
    for (i=1; i<=n; i++)
        scanf ("%d",&t[i]);
    for (i=1; i<=n; i++)
    {
        if (t[i]==1)
            cnt++;
        if (t[i]==0)
            cnt=0;
        out=max(cnt,out);
    }
    for (i=1; i<=n; i++)
        if (t[i]==0)
            break;
    alt=i-1;
    for (i=n; i>=0; i--)
        if (t[i]==0)
            break;
    alt+=n-i;
    printf ("%d\n",max(out,alt));
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H, h, sum, out, dep, t [200001];
int n, i, j;

int main ()
{
    scanf ("%lld%d",&H,&n);
    for (i=1; i<=n; i++)
        scanf ("%lld",&t[i]);
    for (i=1; i<=n; i++)
        {
        sum+=t[i];
        dep=min(dep,sum);
        }
    sum=-sum;
    dep=-dep;
    if (sum<=0 && dep<H)
        return printf ("-1"), 0;
    h=H-dep;
    if (h>0)
        {
        out+=n*((h+sum-1)/sum);
        H-=sum*((h+sum-1)/sum);
        }
    if (H==0)
        return printf ("%lld\n",out), 0;
    for (i=1; i<=n; i++)
        {
        H+=t[i];
        if (H<=0)
            return printf ("%lld\n",out+i), 0;
        }
    return 0;
}
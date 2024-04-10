#include<bits/stdc++.h>
#define maxn 300

using namespace std;
typedef long long ll;

ll p[maxn],y,l,r,mid,query,w,t,f,n,m,k;

ll cnt(ll x)
{
    ll rt=0;
    for (int i=0;i<(1<<w);i++)
    {
        ll tmp=1; f=1;
        for (int j=0;j<w;j++)
            if (i&(1<<j)) tmp*=p[j],f=-f;
        rt+=f*(x/tmp);
    }
    return rt;
}

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        scanf("%d%d%d",&m,&n,&k);w=0;
        int j=2; t=n;
        while (j*j<=t)
        {
            if (t%j==0){
                p[w++]=j;
                while (t%j==0) t/=j;
            }
            j++;
        }
        if (t>1) p[w++]=t;
        k+=cnt(m);
        l=1; r=1000000000000000ll;
        while (r-l>1)
        {
            mid=(l+r)/2;
            if (cnt(mid)<k) l=mid; else r=mid;
        }
        printf("%I64d\n",r);
    }
    return 0;
}
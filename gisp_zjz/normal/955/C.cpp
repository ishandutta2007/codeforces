#include<bits/stdc++.h>
#define maxn 234050

using namespace std;
typedef long long ll;
ll mu[70],d[70],l,r,p,q,mid,query,ans;

ll pow_(ll x,ll y)
{
    ll t=1;
    while (y){
        if (y&1) t*=x;
        x*=x; y>>=1;
    }
    return t;
}

ll cnt(ll x)
{
    ll rt=0;
    for (int i=1;i<=64;i++)
    {
        l=0; r=d[i]+1;
        while (r-l>1){
            mid=(l+r)/2;
            if (pow_(mid,i)>x) r=mid; else l=mid;
        }
        rt+=mu[i]*l;
    }
    return rt;
}

int main()
{
    mu[1]=1;
    for (int i=1;i<70;i++)
        for (int j=2;i*j<70;j++)
            mu[i*j]-=mu[i];
    for (int i=1;i<=64;i++)
        d[i]=(ll)pow(2e18,1.0/i);
    cin >> query;
    while (query--)
    {
        scanf("%lld%lld",&p,&q);
        ans=(p==1); if (p!=1) p--;
        printf("%lld\n",ans+q-p+cnt(p)-cnt(q));
    }
    return 0;
}
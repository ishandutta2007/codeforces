#include<iostream>
#include<cstdio>
#include<cmath>
#define N 200010
#define ll long long
using namespace std;
ll l1,r1,l2,r2;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        ll n;
        ll k,v=0,w=0;
        scanf("%lld%lld%lld%lld%lld%lld",&n,&k,&l1,&r1,&l2,&r2);
        if(l1>l2) swap(l1,l2),swap(r1,r2);
        if(r1>=r2) v=0,k-=(r2-l2)*n,w=r1-l1-(r2-l2);
        else if(r1>=l2) v=0,k-=(r1-l2)*n,w=r2-l1-(r1-l2);
        else v=l2-r1,w=r2-l1;
        if(k<=0){puts("0");continue;}
        if(v>w)
        {
            ll ans=v+w;
            k-=w;
            printf("%lld\n",ans+k*2);
        }
        else
        {
            if(n*w<=k)
            {
                ll ans=n*(v+w);
                ans+=(k-n*w)*2;
                printf("%lld\n",ans);
                continue;
            }
            ll q=(k-1)/w+1;
            ll ans=q*(v+w);
            ans-=q*w-k;
            ll res=(q-1)*(v+w);
            res+=(k-(q-1)*w)*2;
            if(q==1) res=ans;
            printf("%lld\n",min(ans,res));
        }
    }
    return 0;
}
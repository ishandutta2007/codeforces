#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

double ans,p,res;
ll r,n,k,m,s,t,o;

int main()
{
    scanf("%lld%lld%lld",&k,&m,&n);
    r=((k-1)/m+1)*m; s=k; t=r-s;
    p=1.0*s/n+0.5*t/n;
    o=ll(1.0/p);
    ans=1.0*o*r;
    res=1.0-p*o;
    ans+=min(res*n,1.0*s);
    res-=min(res,1.0*s/n);
    ans+=res*2.0*n;
    printf("%.10f\n",ans);
    return 0;
}
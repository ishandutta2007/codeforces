#include<iostream>
#include<cstdio>
#include<cstring>
#define N 4000010
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0)
    {
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a>1ll*b*c){puts("-1");continue;}
        if(a<=1ll*b*d){printf("%lld\n",a);continue;}
        // memset(v,0,sizeof(v));
        // ll dmg=0,ans=0,alv=0;
        // for(int i=1;i<=c;i++)
        // {
        //     alv+=v[i];
        //     dmg-=alv;
        //     if((i-1)%d==0) dmg+=a,v[i+1]+=b,v[i+c+1]-=b;
        //     ans=max(ans,dmg);
        // }
		ll t=(a/b)/d;
		ll ans=(t+1)*a-b*d*t*(t+1)/2;
		printf("%lld\n",ans);
        // a+=b;
        // b=1ll*b*d;
        // ll t=a/b;
        // printf("%lld\n",t*a-t*(t-1)/2*b);
    }
    return 0;
}
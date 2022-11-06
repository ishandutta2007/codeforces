#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(a%b){printf("%lld\n",a);continue;}
        ll ans=1e18;
        for(int i=2;1ll*i*i<=b;i++)
        if(b%i==0)
        {
            ll res=1;
            ll c=a;
            while(c%i==0) c/=i,res*=i;
            b/=i;
            while(b%i==0) b/=i,res/=i;
            ans=min(ans,res);
        }
        if(b!=1)
        {
            int c1=0,c2=0;
            ll res=1;
            ll c=a;
            while(c%b==0) ++c2,c/=b,res*=b;
            ans=min(ans,res);
        }
        printf("%lld\n",a/ans);
    }
    return 0;
}
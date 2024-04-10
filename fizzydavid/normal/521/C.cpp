//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input1(x) x=getval()
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+7;
inline int getval()
{
    int __res=0;bool __neg=0;
    char __c;__c=getchar();
    while(__c==' '||__c=='\n')__c=getchar();
    while(__c!=' '&&__c!='\n')
    {
        if(__c=='-')__neg=1;
        else __res=__res*10+__c-'0';
        __c=getchar();
    }
    if(__neg)__res=-__res;
    return __res;
}
char s[100111];
int n,k;
ll fac[100111];
void init()
{
    fac[0]=1;
    for(int i=1;i<=100100;i++)fac[i]=fac[i-1]*i%mod;
}
ll inverse(ll x)
{
    ll ans=1,k=mod-2;
    while(k>0)
    {
        if(k&1)ans=ans*x%mod;
        x=x*x%mod;
        k=k>>1;
    }
    return ans;
}
ll C(int x,int y)
{
    return fac[x]*inverse(fac[y])%mod*inverse(fac[x-y])%mod;
}
int main()
{
    init();
    input2(n,k);
    scanf("%s",s);
    ll ans=0,pow10=1,sum=0;
    for(int i=0;i<n-1;i++)sum+=s[i]-'0';
    for(int i=1;i<=n-k;i++)
    {
        ans=(ans+pow10*sum%mod*C(n-i-1,k-1)%mod+pow10*(s[n-i]-'0')%mod*C(n-i,k)%mod)%mod;
        pow10=pow10*10%mod;
        sum-=s[n-i-1]-'0';
    }
    printf("%I64d\n",ans);
    return 0;
}
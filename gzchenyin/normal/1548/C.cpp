#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int del(int x,int y){return x>=y?x-y:x+mod-y;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline void Del(int &x,int y){x-=y;if(x<0) x+=mod;}
inline void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
struct num3{
    int val[3];
    num3()
    {
        val[0]=val[1]=val[2]=0;
    }
    num3 operator + (num3 x)
    {
        num3 ans;
        for(int i=0;i<3;i++)
        {
            ans.val[i]=add(val[i],x.val[i]);
        }
        return ans;
    }
    num3 operator - (num3 x)
    {
        num3 ans;
        for(int i=0;i<3;i++)
        {
            ans.val[i]=del(val[i],x.val[i]);
        }
        return ans;
    }
    num3 operator * (num3 x)
    {
        num3 ans;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i+j>=3) Add(ans.val[i+j-3],1ll*val[i]*x.val[j]%mod);
                else Add(ans.val[i+j],1ll*val[i]*x.val[j]%mod);
            }
        }
        return ans;
    }
};
long long fast_pow(long long x,long long y)
{
    long long ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
long long Fac[6000005],Inv[6000005];
void Init()
{
    Fac[0]=1;
    for(int i=1;i<=6000000;i++) Fac[i]=Fac[i-1]*i%mod;
    Inv[6000000]=fast_pow(Fac[6000000],mod-2);
    for(int i=6000000;i>=1;i--) Inv[i-1]=Inv[i]*i%mod;
}
long long C(int x,int y)
{
    if(y<0||x<y) return 0;
    return Fac[x]*Inv[y]%mod*Inv[x-y]%mod;
}
int n,q,inv3;
num3 Now[6000005];
num3 F(int x)
{
    num3 ans;
    ans.val[0]=x;
    return ans;
}
int main()
{
    scanf("%d %d",&n,&q);
    inv3=fast_pow(3,mod-2);
    num3 Tmp;
    Tmp.val[1]=1;
    Init();
    Now[0].val[0]=n+1;
    Now[0].val[1]=Now[0].val[2]=n;
    for(int i=1;i<=3*n;i++)
    {
        Now[i]=Tmp*(Now[i-1]-F(C(3*n,i))-F(C(3*n,i-1)));
        num3 tmp;
        long long t=C(3*n+1,i+1);
        tmp.val[0]=(t+Now[i].val[0]-Now[i].val[1]+mod)*inv3%mod;
        tmp.val[1]=(t+Now[i].val[1]-Now[i].val[2]+mod)*inv3%mod;
        tmp.val[2]=(t+Now[i].val[2]-Now[i].val[0]+mod)*inv3%mod;
        Now[i]=tmp;
    }
    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",Now[x].val[0]);
    }
    return 0;
}
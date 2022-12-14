#include<iostream>
#include<cstdio>
#define ll long long
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
struct poly
{
    int k;
    double s[1005];
    poly operator +(poly y)
    {
        poly c;c.k=max(k,y.k);
        for(int i=1;i<=c.k;i++) c.s[i]=s[i]+y.s[i];
        return c;
    }
    poly operator *(poly y)
    {
        poly c;c.k=k+y.k;
        for(int i=1;i<=k;i++)
            for(int j=1;j<=y.k;j++)
                c.s[i+j-1]+=s[i]*y.s[j];
        while(c.k&&c.s[c.k]==0)c.k--;
        return c;
    }
    int sum(int x)
    {
        int sum=0;
        for(int i=1,y=1;i<=k;i++,y*=x)
            sum+=y*s[i];
        return sum;
    }
    void operator*=(int y)
    {
        for(int i=1;i<=k;i++)
            s[i]*=y;
    }
    void operator/=(int y)
    {
        for(int i=1;i<=k;i++)
            s[i]/=y;
    }
    void print()
    {
        printf("%d\n",k);
        for(int i=1;i<=k;i++) printf("%lf ",s[i]);
        puts("");
    }
}P;

ll pow(ll x,int p)
{
    ll sum=1;
    for(ll i=x;p;p>>=1,i=(i*i)%mod)if(p&1)
        sum=sum*i%mod;
    return sum;
}

int n;
ll ans=0,K,y=0;

void solve()
{
    ll sum=0;
    for(int i=1;i<=n;i++)
        sum=(sum+pow(i,K))%mod;
    printf("%d",(int)sum);
}

int main()
{
    n=read();K=read();
    if(n<=K+1){solve();return 0;}
    ll sum1=n,sum2=1;
    for(int i=1;i<=K+1;i++)
        sum1=sum1*(n-i)%mod,sum2=sum2*(mod-i)%mod;
    for(ll i=1;i<=K+1;i++)
    {
        y=(y+pow(i,K))%mod;
        ll sum3=sum1*pow(n-i,mod-2)%mod;
        sum2=sum2*i%mod;
        sum2=sum2*pow(mod-K+i-2,mod-2)%mod;
     //   cout<<i<<" "<<y<<" "<<sum3<<" "<<sum2<<endl;
        ans=(ans+y*sum3%mod*pow(sum2,mod-2))%mod;
    }
    printf("%d\n",(int)ans);
    return 0;
}
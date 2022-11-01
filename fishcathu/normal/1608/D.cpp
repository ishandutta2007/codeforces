#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=1E5+10;
const int inf=1<<30;
template<typename T>T min(T x){return x;}
template<typename T>T max(T x){return x;}
template<typename T,typename...Args>auto min(T l,Args...args){auto r=min(args...);return l<r?l:r;}
template<typename T,typename...Args>auto max(T l,Args...args){auto r=max(args...);return l>r?l:r;}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
template<typename T=int>T read()
{
    T a=0;int b=1;char c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
const int p=998244353;
int fac[N],inv[N],n;
char a[N][2];
int c(int l,int r){return r<0||r>l?0:fac[l]*1LL*inv[r]%p*inv[l-r]%p;}
int calc1()
{
    int l=0,r=0,u=0,v=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i][0]=='B')++l;
        else if(a[i][0]=='?')++u;
        if(a[i][1]=='W')++r;
        else if(a[i][1]=='?')++v;
    }
    int ans=0;
    for(int i=0;i<=n;++i)ans=(ans+c(u,i-l)*1LL*c(v,i-r))%p;
    return ans;
}
int calc2()
{
    int ans=1;
    for(int i=1;i<=n;++i)if(a[i][0]==a[i][1])
    {
        if(a[i][0]^'?')return 0;
        ans=ans*2%p;
    }
    return ans;
}
int calc3()
{
    int l=1,r=1;
    for(int i=1;i<=n;++i)
    {
        if(a[i][0]=='B'||a[i][1]=='W')l=0;
        if(a[i][0]=='W'||a[i][1]=='B')r=0;
    }
    return l+r;
}
int main()
{
    n=read();
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=2;i<=n;++i)fac[i]=fac[i-1]*1LL*i%p,inv[i]=inv[i-1]*1LL*inv[i]%p;
    for(int i=1;i<=n;++i)scanf("%s",a[i]);
    cout<<((calc1()-calc2()+calc3())%p+p)%p<<'\n';
}
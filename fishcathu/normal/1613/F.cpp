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
const int N=2.5E5+10;
const int inf=1<<30;
template<typename T>T min(T x){return x;}
template<typename T>T max(T x){return x;}
template<typename T,typename...Args>auto min(T l,Args...args){auto r=min(args...);return l<r?l:r;}
template<typename T,typename...Args>auto max(T l,Args...args){auto r=max(args...);return l>r?l:r;}
template<typename T>bool cmin(T &l,T r){return l>r?l=r,1:0;}
template<typename T>bool cmax(T &l,T r){return l<r?l=r,1:0;}
template<typename T=int>T read()
{
    T a=0;int b=1;char c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
const int p=998244353;
int fac[N],inv[N];
int du[N];
int c(int n,int m){return fac[n]*1LL*inv[m]%p*inv[n-m]%p;}
int qpow(int x,int n){int ans=1;while(n){if(n&1)ans=ans*1LL*x%p;x=x*1LL*x%p,n>>=1;}return ans;}
queue<vector<int>>q;
void ntt(vector<int>&a,int n,bool op)
{
    for(int i=0,j=0;i<n;++i)
    {
        if(i<j)swap(a[i],a[j]);
        for(int k=n>>1;(j^=k)<k;k>>=1);
    }
    for(int i=1;i<n;i<<=1)
    {
        for(int j=0,w=qpow(3,p/i>>1),t=1;j<n;)
        {
            int k=j^i;
            if(k<j)t=1,j+=i;
            else
            {
                int u=a[j],v=a[k]*1LL*t%p;
                a[j]=(u+v)%p;
                a[k]=(u-v+p)%p;
                t=t*1LL*w%p;
                ++j;
            }
        }
    }
    if(op)return;
    reverse(&a[1],&a[n]);
    for(int i=0,t=qpow(n,p-2);i<n;++i)a[i]=a[i]*1LL*t%p;
}
void merge(vector<int>&a,vector<int>&b)
{
    int s=1<<__lg(a.size()+b.size()-2)+1;
    a.resize(s);
    b.resize(s);
    ntt(a,s,1);
    ntt(b,s,1);
    for(int i=0;i<s;++i)a[i]=a[i]*1LL*b[i]%p;
    ntt(a,s,0);
}
int main()
{
    int n=read();
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=2;i<=n;++i)fac[i]=fac[i-1]*1LL*i%p,inv[i]=inv[i-1]*1LL*inv[i]%p;
    for(int i=n;--i;)++du[read()],++du[read()];
    ++du[1];
    for(int i=1;i<=n;++i)if(--du[i])q.push({1,du[i]});
    while(q.size()>1)
    {
        vector<int>a=q.front();
        q.pop();
        vector<int>b=q.front();
        q.pop();
        merge(a,b);
        q.push(a);
    }
    vector<int>a=q.front();
    int ans=0;
    for(int i=min(a.size()-1,n);i>=0;--i)
    {
        if(i&1)ans=(ans+a[i]*1LL*(p-fac[n-i]))%p;
        else ans=(ans+a[i]*1LL*fac[n-i])%p;
    }
    cout<<ans<<'\n';
}
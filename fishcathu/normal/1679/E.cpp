#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define eb emplace_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
constexpr int N=1010,S=1<<17;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U l,V r){return l<r?l:r;}
template<typename U,typename V>auto max(U l,V r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename U,typename V>bool cmin(U &l,V r){return l>r?l=r,1:0;}
template<typename U,typename V>bool cmax(U &l,V r){return l<r?l=r,1:0;}

int a[N],f[18][S],n,m;
void init(int l,int r)
{
    for(int u=0,v=m;l>=1&&r<=n;--l,++r)
    {
        if(l^r)
        {
            int x=a[l],y=a[r];
            if(x>y)swap(x,y);
            if(y<0)--v;
            else if(x<0)u|=1<<y,--v;
            else if(x^y)break;
        }
        for(int i=1;i<18;++i)f[i][u]=(f[i][u]+qpow(i,v))%p;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>n;
    for(int i=1;i<=n;++i)m+=(a[i]=read<char>()-97)<0;
    for(int i=1;i<=n;++i)init(i,i),init(i,i+1);
    for(int i=1;i<18;++i)
    {
        for(int k=1;k<S;k<<=1)
        {
            for(int j=0;j<S;++j)if(j&k)
            {
                f[i][j]=(f[i][j]+f[i][j^k])%p;
            }
        }
    }
    for(int T=read();T--;)
    {
        int u=0;
        for(char x:read<string>())u|=1<<x-97;
        cout<<f[__builtin_popcount(u)][u]<<'\n';
    }
}
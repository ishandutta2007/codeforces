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
constexpr int N=2E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],q[N];
bool solve()
{
    int n=0,s=0,k=0;
    for(char x:read<string>())
    {
        ++n;
        if(x=='(')k+=a[n]=1;
        else if(x==')')k+=a[n]=-1;
        else q[++s]=n;
    }
    int x=s-k>>1;
    if(!x||x==s)return 1;
    for(int i=1;i<x;++i)a[q[i]]=1;
    for(int i=x+2;i<=s;++i)a[q[i]]=-1;
    a[q[x]]=-1;
    a[q[x+1]]=1;
    for(int i=1,t=0;i<=n;++i)
    {
        t+=a[i];
        if(t<0)return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;cout<<(solve()?"YES":"NO")<<'\n');
}
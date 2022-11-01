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

int a[N],fa[N],F[N<<1],*f=F+N;
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
void merge(int x,int y){fa[find(y)]=find(x);}
void solve()
{
    int n=read()<<1;
    for(int i=-n;i<=n;++i)f[i]=-1;
    f[0]=0;
    for(int i=1,x=0;i<=n;++i)
    {
        int &j=f[x+=a[i]=81-read<char>()*2];
        fa[i]=i;
        if(!~a[i]&&~j)
        {
            merge(j+1,i);
            if(!~a[j]&&find(j)^j)merge(j,i);
        }
        j=i;
    }
    int ans=0;
    for(int i=1;i<=n;++i)ans+=fa[i]==i;
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}
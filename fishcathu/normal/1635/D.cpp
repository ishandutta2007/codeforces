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
constexpr int p=1E9+7;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    vector<int>a(read());
    int n=read();
    for(int &x:a)cin>>x;
    sort(a.begin(),a.end());
    set<int>h;
    for(int x:a)
    {
        int y=x;
        while(y&&!h.count(y))
        {
            if(y&1)y>>=1;
            else if(!(y&3))y>>=2;
            else break;
        }
        if(!h.count(y))++f[__lg(x)+1],h.insert(x);
    }
    int ans=f[1];
    for(int i=2;i<=n;++i)(ans+=(f[i]+=f[i-1]+f[i-2])%=p)%=p;
    cout<<ans<<'\n';
}
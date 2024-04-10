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
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

char u[N];
void solve()
{
    int a=read(),b=read(),c=read(),d=read();
    cin>>u;
    int n=strlen(u);
    if(count(u,u+n,'A')^a+c+d)return cout<<"NO\n",void();
    int s=0;
    vector<int>y,z;
    for(int i=0,j=0;i<n;i=j)
    {
        while(++j<n&&u[j]^u[j-1]);
        int x=j-i;
        s+=x-1>>1;
        if(~x&1)(u[i]&1?y:z).pb(x>>1);
    }
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    for(int t=c;int x:y)if(t>=x)--c,t-=x;
    for(int t=d;int x:z)if(t>=x)--d,t-=x;
    cout<<(s>=c+d?"YES":"NO")<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}
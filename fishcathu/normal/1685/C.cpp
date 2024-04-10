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

int a[N];
void solve()
{
    int n=read()<<1,l=0,r;
    for(int i=1;i<=n;++i)
    {
        if((a[i]=a[i-1]+81-read<char>()*2)<0)
        {
            if(!l)l=i;
            r=i;
        }
    }
    if(!l)return cout<<"0\n",void();
    int x=max_element(a,a+l)-a;
    int y=max_element(a,a+n+1)-a;
    int z=max_element(a+r+1,a+n+1)-a;
    if(a[x]+a[z]>=a[y])cout<<"1\n"<<x+1<<' '<<z<<'\n';
    else cout<<"2\n1 "<<y<<'\n'<<y+1<<' '<<n<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}
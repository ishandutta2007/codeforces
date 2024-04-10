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
constexpr int N=3E5+10;
constexpr int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],f[N],n,m,p,s;
void calc(int &x,int k){s-=x!=0,(x+=k)%=p,s+=x!=0;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>n>>m>>p;
    f[0]=f[1]=1;
    for(int i=2;i<=n;++i)f[i]=(f[i-2]+f[i-1])%p;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)a[i]-=read();
    for(int i=n;i>=2;--i)a[i]=((a[i]-a[i-1])%p-a[i-2])%p;
    for(int i=1;i<=n;++i)s+=a[i]!=0;
    while(m--)
    {
        int k=read<char>()&1?1:-1,l=read(),r=read();
        calc(a[l],k);
        if(r+1<=n)calc(a[r+1],-k*f[r-l+1]);
        if(r+2<=n)calc(a[r+2],-k*f[r-l]);
        cout<<(s?"No":"Yes")<<'\n';
    }
}
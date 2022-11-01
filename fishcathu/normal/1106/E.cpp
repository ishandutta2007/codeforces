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
constexpr int N=1E5+10;
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

struct node
{
    int w,d,l;
    bool operator<(const node m)const
    {
        return w<m.w||w==m.w&&d<m.d;
    }
};
ll f[N][210];
vector<node>to[N];
priority_queue<node>q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    for(int T=read();T--;)
    {
        int l=read(),r=read(),d=read(),w=read();
        to[r].pb({w,d,l});
    }
    q.push({});
    for(int i=n;i>=1;--i)
    {
        for(node x:to[i])q.push(x);
        while(q.top().l>i)q.pop();
        auto [w,j,l]=q.top();
        for(int k=0;k<=m;++k)
        {
            f[i][k]=f[max(j,i)+1][k]+w;
            if(k<m)cmin(f[i][k],f[i+1][k+1]);
        }
    }
    cout<<f[1][0]<<'\n';
}
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
constexpr int N=5E5+10;
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

struct node{int x,id;bool operator<(const node t)const{return x>t.x;}};
vector<node>to[N];
priority_queue<node>q;
int ans[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)to[i].clear();
    for(int i=1;i<=n;++i)
    {
        int x=read();
        to[i/(x+1)+1].pb({x?i/x:n,i});
    }
    for(int i=1;i<=n;++i)
    {
        for(node x:to[i])q.push(x);
        ans[q.top().id]=i;
        q.pop();
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}
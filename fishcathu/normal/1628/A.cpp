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
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
const int N=2E5+10;
const int inf=1<<30;
int a[N],head[N],nex[N],q[N],s;
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=n;i>=1;--i)nex[i]=head[a[i]],head[a[i]]=i;
    int p=0;
    while(1)
    {
        int x=0,i=0;
        while(1)
        {
            while(head[i]&&head[i]<=p)head[i]=nex[head[i]];
            if(!head[i])break;
            cmax(x,head[i++]);
        }
        if(!i)break;
        q[++s]=i;
        p=x;
    }
    for(int i=n-p;i--;q[++s]=0);
    cout<<s<<'\n';
    for(int i=1;i<=s;++i)cout<<q[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;++i)head[i]=0;
    s=0;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}
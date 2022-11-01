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
const int N=2E5+10;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N],b[N],c[N];
vector<pii>q[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)c[i]=0;
    for(int i=1;i<=n;++i)
    {
        ++c[a[i]=read()];
        q[c[a[i]]].pb({a[i],i});
    }
    for(int i=1;!q[i].empty();++i)
    {
        int s=q[i].size();
        sort(q[i].begin(),q[i].end());
        for(int j=0;j<s;++j)b[q[i][j][1]]=a[q[i][(j+1)%s][1]];
        q[i].clear();
    }
    for(int i=1;i<=n;++i)cout<<b[i]<<' ';
    cout<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}
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
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

vector<int>to[N];
int a[N],len[N],du[N],n,m;
ll y;
queue<int>q;
bool check(int k)
{
    for(int i=1;i<=n;++i)len[i]=du[i]=0;
    for(int i=1;i<=n;++i)if(a[i]<=k)for(int j:to[i])du[j]+=a[j]<=k;
    for(int i=1;i<=n;++i)if(a[i]<=k&&!du[i])q.push(i);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        ++len[x];
        for(int t:to[x])if(a[t]<=k)
        {
            cmax(len[t],len[x]);
            if(!--du[t])q.push(t);
        }
    }
    return *max_element(len+1,len+1+n)>=y||*max_element(du+1,du+1+n);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    cin>>n>>m>>y;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)to[read()].pb(read());
    int l=1,r=inf+1;
    while(l^r)
    {
        int mid=l+r>>1;
        check(mid)?r=mid:l=mid+1;
    }
    cout<<(l>inf?-1:l)<<'\n';
}
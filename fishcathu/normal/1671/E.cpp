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
const int N=1<<18;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

const int p=998244353;
string a[N];
int ans[N];
void dfs(int i,int k)
{
    if(k==1)return ans[i]=1,void();
    dfs(ls,k-1);
    dfs(rs,k-1);
    ans[i]=1LL*ans[ls]*ans[rs]%p;
    if(a[ls]!=a[rs])ans[i]=ans[i]*2%p;
    if(a[ls]<a[rs])a[i]+=a[ls]+a[rs];
    else a[i]+=a[rs]+a[ls];
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=1;i<1<<n;++i)a[i]=read<char>();
    dfs(1,n);
    cout<<ans[1]<<'\n';
}
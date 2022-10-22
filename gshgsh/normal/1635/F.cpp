#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 1000001
int N,M,x[MAXN],w[MAXN],p[MAXN],l[MAXN],r[MAXN],mx[MAXN],mn[MAXN],a[MAXN],b[MAXN];ll c[MAXN],ans[MAXN];vector<pair<int,int>>opt[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void updmx(int x){for(int i=x;i<=N;i+=lowbit(i))mx[i]=max(mx[i],x);}int askmx(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans=max(ans,mx[i]);return ans;}
void updmn(int x){for(int i=x;i;i-=lowbit(i))mn[i]=min(mn[i],x);}int askmn(int x){int ans=N+1;for(int i=x;i<=N;i+=lowbit(i))ans=min(ans,mn[i]);return ans;}
void upd(int x,ll v){for(int i=x;i;i-=lowbit(i))c[i]=min(c[i],v);}ll ask(int x){ll ans=5e18;for(int i=x;i<=N;i+=lowbit(i))ans=min(ans,c[i]);return ans;}
int main()
{
	N=get(),M=get();For(i,1,N)x[i]=get(),w[i]=get(),p[i]=i;sort(p+1,p+N+1,[&](const int&x,const int&y){return w[x]<w[y]||w[x]==w[y]&&x<y;});
	For(i,1,N)l[p[i]]=askmx(p[i]-1),updmx(p[i]);For(i,1,N)mn[i]=N+1;For(i,1,N)r[p[i]]=askmn(p[i]+1),updmn(p[i]);
	For(i,1,N){if(l[i])opt[i].push_back({0,l[i]});if(r[i]<=N)opt[r[i]].push_back({0,i});}For(i,1,M)a[i]=get(),b[i]=get(),opt[b[i]].push_back({1,i});For(i,1,N)c[i]=5e18;
	For(i,1,N)for(auto j:opt[i]){if(j.first==0){int a=j.second,b=i;upd(a,1ll*(x[b]-x[a])*(w[a]+w[b]));}else ans[j.second]=ask(a[j.second]);}For(i,1,M)cout<<ans[i]<<'\n';
}
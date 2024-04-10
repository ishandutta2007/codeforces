#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
#define int long long
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 100001
int T,N,K,a[MAXN],x,mx[MAXN];ll s[MAXN],val[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int x,int v){for(int i=x;i;i-=lowbit(i))mx[i]=max(mx[i],v);}
int ask(int x){if(!x)x=1;int ans=-1;for(int i=x;i<=K;i+=lowbit(i))ans=max(ans,mx[i]);return ans;}
signed main()
{
	T=get();
	while(T--)
	{
		N=K=0;memset(a,0,sizeof(a));memset(mx,-1,sizeof(mx));memset(s,0,sizeof(s));memset(val,0,sizeof(val));
		N=get();For(i,1,N)a[i]=get();x=get();For(i,1,N)val[i]=s[i]=s[i-1]+a[i]-x;val[N+1]=0;
		sort(val+1,val+N+2);K=unique(val+1,val+N+2)-val-1;For(i,0,N)s[i]=lower_bound(val+1,val+K+1,s[i])-val;
		int tot=0,r=0;For(i,1,N){int x=ask(s[i]+1)+1;if(x&&x<i)if(r<x)r=i,tot++;upd(s[i-1],i-1);}cout<<N-tot<<'\n';
	}
}
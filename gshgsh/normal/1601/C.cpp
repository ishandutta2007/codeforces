#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 2000001
int T,N,M,K,a[MAXN],b[MAXN],val[MAXN*2],c[MAXN*2],tg[MAXN*8],mn[MAXN*8];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void build(int k,int l,int r){if(l!=r)build(ls(k),l,R),build(rs(k),L,r);mn[k]=tg[k]=0;}
void pt(int k,int v){tg[k]+=v,mn[k]+=v;}void dwn(int k){if(tg[k])pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),mn[k]=min(mn[ls(k)],mn[rs(k)]):(pt(k,v),0):0;}
void add(int x,int v){for(int i=x;i<=K;i+=lowbit(i))c[i]+=v;}int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
ll getcnt(){ll ans=0;For(i,1,K)c[i]=0;For(i,1,N)ans+=ask(K)-ask(a[i]),add(a[i],1);return ans;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=get(),val[i]=a[i];For(i,1,M)b[i]=get(),val[i+N]=b[i];
		sort(val+1,val+N+M+1);K=unique(val+1,val+N+M+1)-val-1;For(i,1,N)a[i]=lower_bound(val+1,val+K+1,a[i])-val;
		For(i,1,M)b[i]=lower_bound(val+1,val+K+1,b[i])-val;sort(b+1,b+M+1);
		build(1,0,N);ll ans=getcnt();For(i,1,N)upd(1,0,N,i,N,1);
		vector<pair<int,int>>val;For(i,1,N)val.push_back({a[i],i});sort(val.begin(),val.end());int j1=0,j2=0;
		For(i,1,M)
		{
			while(j1<N&&val[j1].first<=b[i])upd(1,0,N,val[j1].second,N,-1),j1++;
			while(j2<N&&val[j2].first<b[i])upd(1,0,N,0,val[j2].second-1,1),j2++;
			ans+=mn[1];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
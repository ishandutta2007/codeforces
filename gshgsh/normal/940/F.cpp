#include<algorithm>
#include<iostream>
#include<cassert>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,M,Q,T,B,a[MAXN],opt[MAXN],x[MAXN],y[MAXN],K,b[MAXN],cnt[MAXN],tot[MAXN],res=1,ans[MAXN];struct que{int l,r,t,id;}q[MAXN];vector<int>v[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void ins(int x)
{
	tot[cnt[a[x]]++]--;tot[cnt[a[x]]]++;
	if(res>cnt[a[x]]-1&&!tot[cnt[a[x]]-1])res=cnt[a[x]]-1;
	if(res==cnt[a[x]])while(tot[res])res++;
}
void era(int x)
{
	tot[cnt[a[x]]--]--;tot[cnt[a[x]]]++;
	if(res>cnt[a[x]]+1&&!tot[cnt[a[x]]+1])res=cnt[a[x]]+1;
	if(res==cnt[a[x]])while(tot[res])res++;
}
void ins1(int l,int r,int t){if(x[t]>=l&&x[t]<=r)era(x[t]);v[x[t]].push_back(a[x[t]]=y[t]);if(x[t]>=l&&x[t]<=r)ins(x[t]);}
void era1(int l,int r,int t){if(x[t]>=l&&x[t]<=r)era(x[t]);v[x[t]].pop_back();a[x[t]]=v[x[t]].back();if(x[t]>=l&&x[t]<=r)ins(x[t]);}
int main()
{
	N=get(),M=get(),B=max(N/pow(M,1.0/3),1.0);For(i,1,N)a[i]=get(),b[++K]=a[i];For(i,1,M)opt[i]=get(),x[i]=get(),y[i]=get(),opt[i]==2&&(b[++K]=y[i]);
	sort(b+1,b+K+1);K=unique(b+1,b+K+1)-b-1;For(i,1,N)a[i]=lower_bound(b+1,b+K+1,a[i])-b;For(i,1,M)if(opt[i]==2)y[i]=lower_bound(b+1,b+K+1,y[i])-b;For(i,1,N)v[i].push_back(a[i]);
	For(i,1,M)if(opt[i]==2)x[++T]=x[i],y[T]=y[i];else Q++,q[Q]={x[i],y[i],T,Q};sort(q+1,q+Q+1,[&](const que&a,const que&b){return a.l/B!=b.l/B?a.l<b.l:a.r/B!=b.r/B?a.r<b.r:a.t<b.t;});int l=1,r=0,t=0;cnt[0]=1e9;
	For(i,1,Q)
	{
		while(l>q[i].l)ins(--l);while(r<q[i].r)ins(++r);while(l<q[i].l)era(l++);while(r>q[i].r)era(r--);
		while(t<q[i].t)ins1(l,r,++t);while(t>q[i].t)era1(l,r,t--);ans[q[i].id]=res;
	}
	For(i,1,Q)cout<<ans[i]<<'\n';return 0;
}
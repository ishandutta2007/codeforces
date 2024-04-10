#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 2000001
int N,a[MAXN],mn[MAXN],tg[MAXN],sum[MAXN];vector<int>pos[MAXN];vector<pair<pair<int,int>,int>>val[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void build(int k,int l,int r){if(l!=r)build(ls(k),l,R),build(rs(k),L,r);sum[k]=r-l+1;}
void pt(int k,int v){mn[k]+=v,tg[k]+=v;}void dwn(int k){pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return pt(k,v);dwn(k);x<=R&&(upd(ls(k),l,R,x,y,v),0),y>=L&&(upd(rs(k),L,r,x,y,v),0),mn[k]=min(mn[ls(k)],mn[rs(k)]),sum[k]=(mn[k]==mn[ls(k)])*sum[ls(k)]+(mn[k]==mn[rs(k)])*sum[rs(k)];}
int main()
{
	N=get();For(i,1,N)pos[i].push_back(0);For(i,1,N)a[i]=get(),pos[a[i]].push_back(i);For(i,1,N)pos[i].push_back(N+1);build(1,1,N);
	For(i,1,N)
	{
		if(i>1)val[i].push_back({{1,i-1},1});int M=pos[i].size();if(M==2)continue;auto v=pos[i];
		For(j,1,M-5)val[1].push_back({{v[j+3],N},1}),val[v[j]+1].push_back({{v[j+3],N},-1});
		if(M==3)val[1].push_back({{v[1],N},1}),val[v[1]+1].push_back({{v[1],N},-1});
		else
		{
			For(j,1,M-3)val[v[j-1]+1].push_back({{v[j],v[j+2]-1},1}),val[v[j]+1].push_back({{v[j],v[j+2]-1},-1});
			For(j,2,M-2)val[v[j-2]+1].push_back({{v[j],v[j+1]-1},1}),val[v[j]+1].push_back({{v[j],v[j+1]-1},-1});
		}
	}
	ll ans=0;For(i,1,N){for(auto j:val[i])upd(1,1,N,j.first.first,j.first.second,j.second);if(!mn[1])ans+=sum[1];}cout<<ans<<'\n';return 0;
}
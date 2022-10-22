#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 500001
int N,M,p[MAXN],top,sta[MAXN],l1[MAXN],r1[MAXN],l2[MAXN],r2[MAXN],mn[MAXN],cnt[MAXN],tg[MAXN],tm[MAXN];ll ans[MAXN],res[MAXN];vector<pair<int,pair<int,int>>>u[MAXN];vector<pair<pair<int,int>,pair<int,int>>>q[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void pushup(int k){mn[k]=min(mn[ls(k)],mn[rs(k)]);cnt[k]=0;mn[k]==mn[ls(k)]&&(cnt[k]+=cnt[ls(k)]),mn[k]==mn[rs(k)]&&(cnt[k]+=cnt[rs(k)]),ans[k]=ans[ls(k)]+ans[rs(k)];}
void build(int k,int l,int r){if(l!=r)build(ls(k),l,R),build(rs(k),L,r),pushup(k);else mn[k]=-l,cnt[k]=1;}
void pt1(int k,int v){mn[k]+=v,tg[k]+=v;}void pt2(int k,int v){ans[k]+=1ll*v*cnt[k],tm[k]+=v;}
void dwn(int k){pt1(ls(k),tg[k]),pt1(rs(k),tg[k]),mn[ls(k)]==mn[k]&&(pt2(ls(k),tm[k]),0),mn[rs(k)]==mn[k]&&(pt2(rs(k),tm[k]),0),tg[k]=tm[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return pt1(k,v);dwn(k);x<=R&&(upd(ls(k),l,R,x,y,v),0),y>=L&&(upd(rs(k),L,r,x,y,v),0),pushup(k);}
ll ask(int k,int l,int r,int x,int y){if(l>=x&&r<=y)return ans[k];dwn(k);ll res=0;x<=R&&(res+=ask(ls(k),l,R,x,y)),y>=L&&(res+=ask(rs(k),L,r,x,y));return res;}
int main()
{
	N=get();For(i,1,N)p[i]=get();build(1,1,N);
	sta[top=0]=0;For(i,1,N){while(top&&p[sta[top]]<p[i])top--;l1[i]=sta[top]+1;sta[++top]=i;}
	sta[top=0]=N+1;FOR(i,N,1){while(top&&p[sta[top]]<p[i])top--;r1[i]=sta[top]-1;sta[++top]=i;}
	sta[top=0]=0;For(i,1,N){while(top&&p[sta[top]]>p[i])top--;l2[i]=sta[top]+1;sta[++top]=i;}
	sta[top=0]=N+1;FOR(i,N,1){while(top&&p[sta[top]]>p[i])top--;r2[i]=sta[top]-1;sta[++top]=i;}
	For(i,1,N)u[l1[i]].push_back({p[i],{i,r1[i]}}),u[i+1].push_back({-p[i],{i,r1[i]}});
	For(i,1,N)u[l2[i]].push_back({-p[i],{i,r2[i]}}),u[i+1].push_back({p[i],{i,r2[i]}});
	M=get();For(i,1,M){int l=get(),r=get();res[i]=-1ll*(r-l)*(r-l+1)/2;q[l-1].push_back({{-1,i},{l,r}});q[r].push_back({{1,i},{l,r}});}
	For(i,1,N)
	{
		upd(1,1,N,i,N,1);for(auto j:u[i])upd(1,1,N,j.second.first,j.second.second,j.first);
		pt2(1,1);for(auto j:q[i])res[j.first.second]+=j.first.first*ask(1,1,N,j.second.first,j.second.second);
	}
	For(i,1,M)cout<<res[i]<<'\n';return 0;
}
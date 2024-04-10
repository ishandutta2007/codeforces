#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 200001
int N,M,Q,u[MAXN*2],v[MAXN*2],w[MAXN*2],s[MAXN*2],t[MAXN*2],f[MAXN],dis[MAXN],siz[MAXN],p[30],x[MAXN],y[MAXN],top,sta[MAXN*100];vector<int>id[MAXN*4];map<int,int>vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return id[k].push_back(v);x<=R&&(upd(ls(k),l,R,x,y,v),0),y>=L&&(upd(rs(k),L,r,x,y,v),0);}
int getf(int x){return f[x]==x?x:getf(f[x]);}int getd(int x){return f[x]==x?0:dis[x]^getd(f[x]);}
void mrg(int x,int y,int w){x=getf(x),y=getf(y);if(siz[x]>siz[y])swap(x,y);dis[x]=w,f[x]=y,siz[y]+=siz[x];sta[++top]=x;}
void insert(int x){FOR(i,29,0)if((x>>i)&1){if(!p[i]){p[i]=x;return;}x^=p[i];}}
int ask(int x){int ans=x;FOR(i,29,0)ans=min(ans,ans^p[i]);return ans;}
void ask(int k,int l,int r)
{
	int*q=new int[30];For(i,0,29)q[i]=p[i];int lst=top;
	for(auto i:id[k])if(getf(u[i])!=getf(v[i]))mrg(u[i],v[i],w[i]^getd(u[i])^getd(v[i]));else insert(getd(u[i])^getd(v[i])^w[i]);
	if(l!=r)ask(ls(k),l,R),ask(rs(k),L,r);else if(x[l])cout<<ask(getd(x[l])^getd(y[l]))<<'\n';
	For(i,0,29)p[i]=q[i];while(top>lst)dis[sta[top]]=0,siz[f[sta[top]]]-=siz[sta[top]],f[sta[top]]=sta[top],top--;
}
int main()
{
	N=get(),M=get();For(i,1,N)f[i]=i,siz[i]=1;For(i,1,M)u[i]=get(),v[i]=get(),w[i]=get(),s[i]=1,vis[u[i]][v[i]]=vis[v[i]][u[i]]=i;Q=get();
	For(i,1,Q)
	{
		int opt=get(),a=get(),b=get();
		if(opt==1){int c=get();u[++M]=a,v[M]=b,w[M]=c,s[M]=i;vis[a][b]=vis[b][a]=M;}
		else if(opt==2)t[vis[a][b]]=i,vis[a][b]=vis[b][a]=0;else x[i]=a,y[i]=b;
	}
	For(i,1,M)if(!t[i])t[i]=Q;For(i,1,M)upd(1,1,Q,s[i],t[i],i);ask(1,1,Q);return 0;
}
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,Q,x,y,a[100005],rd[100005],h[100005],cnt=1,H[200005],CNT;char c[2];
struct edge{int to,next;}e[400005],E[400005];
void add(int x,int y){e[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void ADD(int x,int y){E[++CNT]=(edge){y,H[x]};H[x]=CNT;}
int Time,dfn[200005],low[200005],stack[100005],tot,BCC;
multiset<int>s[200005];
void tarjan(int x,int prt){
	int i,y;dfn[x]=low[x]=++Time;stack[++tot]=x;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(i==prt)continue;
		if(!dfn[y]){
			tarjan(y,i^1);low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				++BCC;ADD(x,n+BCC);
				do{
					y=stack[tot--];
					ADD(n+BCC,y);
					s[n+BCC].insert(a[y]);
				}while(y!=e[i].to);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
int fa[200005],size[200005],d[200005],son[200005];
void dfs1(int x){
	int i,y;size[x]=1;
	for(i=H[x];i;i=E[i].next){
		y=E[i].to;if(y==fa[x])continue;
		fa[y]=x;d[y]=d[x]+1;dfs1(y);size[x]+=size[y];
		son[x]=size[son[x]]<size[y]?y:son[x];
	}
}
int pos[200005],top[200005];
void dfs2(int x,int Top){
	int i,y;top[pos[dfn[x]=++Time]=x]=Top;
	if(son[x])dfs2(son[x],Top);
	for(i=H[x];i;i=E[i].next){
		y=E[i].to;if(y!=fa[x]&&y!=son[x])dfs2(y,y);
	}
}
int Min[800005];
void pushup(int k){Min[k]=min(Min[k<<1],Min[k<<1|1]);}
void build(int k,int l,int r){
	if(l==r){
		int t=pos[l];Min[k]=(t<=n?a[t]:*s[t].begin());
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x){
	if(l==r){
		int t=pos[l];Min[k]=(t<=n?a[t]:*s[t].begin());
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x);
	else change(k<<1|1,mid+1,r,x);
	pushup(k);
}
int query(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return Min[k];
	}
	int mid=l+r>>1,ans=2e9;
	if(L<=mid)ans=min(ans,query(k<<1,l,mid,L,R));
	if(R>mid)ans=min(ans,query(k<<1|1,mid+1,r,L,R));
	return ans;
}
int Query(int x,int y){
	int ans=1e9;
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]])swap(x,y);	
		ans=min(ans,query(1,1,n+BCC,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	
	if(dfn[x]>dfn[y])swap(x,y);
	ans=min(ans,query(1,1,n+BCC,dfn[x],dfn[y]));
	if(x>n)x=fa[x];ans=min(ans,a[x]);
	return ans;
}
int main(){
	n=read();m=read();Q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i){
		x=read();y=read();
		add(x,y);add(y,x);
		++rd[x];++rd[y];
	}
	tarjan(1,0);dfs1(1);Time=0;dfs2(1,1);
	build(1,1,n+BCC);
	for(int i=1;i<=Q;++i){
		scanf("%s",c);x=read();y=read();
		if(c[0]=='A')cout<<Query(x,y)<<"\n";
		else{
			if(fa[x]) {
				s[fa[x]].erase(s[fa[x]].find(a[x]));
				s[fa[x]].insert(y);
				change(1,1,n+BCC,dfn[fa[x]]);
			}
			a[x]=y;change(1,1,n+BCC,dfn[x]);
		}
	}
}
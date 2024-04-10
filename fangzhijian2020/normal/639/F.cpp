#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=1e9;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,Q,x[300005],y[300005],h[300005],cnt=1;
struct edge{int to,next;}e[600005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int Time,dfn[300005],low[300005],stack[300005],tot,instack[300005],BCC,bl[300005];
void tarjan(int x,int prt){
	int i,y;dfn[x]=low[x]=++Time;instack[stack[++tot]=x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(i==prt)continue;
		if(!dfn[y]){tarjan(y,i^1);low[x]=min(low[x],low[y]);}
		else if(instack[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		++BCC;
		do{
			y=stack[tot--];
			instack[y]=0;
			bl[y]=BCC;
		}while(y!=x);
	}
}
int root[300005],BL[300005],DFN[300005],fa[300005],d[300005],size[300005],son[300005],top[300005];
void dfs1(int x,int rt){
	int i,y;size[x]=1;root[x]=rt;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==fa[x])continue;
		fa[y]=x;d[y]=d[x]+1;dfs1(y,rt);size[x]+=size[y];
		son[x]=size[son[x]]<size[y]?y:son[x];
	}
}
void dfs2(int x,int Top){
	int i,y;dfn[x]=++Time;top[x]=Top;
	if(son[x])dfs2(son[x],Top);
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y!=fa[x]&&y!=son[x])dfs2(y,y);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]])swap(x,y);x=fa[top[x]];
	}
	return d[x]<d[y]?x:y;
}
int p[1000005],t1,t[1000005],P;
struct node{int x,y,z;}q[1000005];int t2;
bool cmp(const int&a,const int&b){return DFN[a]<DFN[b];}
void ADD(int x,int y){
	q[++t2]=(node){x,y};t[++P]=x;t[++P]=y;
}
void vT(int l,int r){
	stack[tot=1]=root[p[l]];
	for(int i=l;i<r;++i){
		int lca=LCA(stack[tot],p[i]);
		if(lca!=stack[tot]){
			while(d[stack[tot-1]]>d[lca]){
				ADD(stack[tot-1],stack[tot]);--tot;
			}
			ADD(stack[tot],lca);--tot;
			if(stack[tot]!=lca)stack[++tot]=lca;
		}
		if(stack[tot]!=p[i])stack[++tot]=p[i];	
	}
	while(tot>1){
		ADD(stack[tot-1],stack[tot]);--tot;
	}
}
int tmp[300005],lastans;
void solve(int id){
	int K,L;t1=0;
	L=read();K=read();
	for(int i=1;i<=L;++i){
		tmp[i]=BL[(read()-1+lastans)%n+1];
		p[++t1]=tmp[i];
	}
	for(int i=1;i<=K;++i){
		x[i]=BL[(read()-1+lastans)%n+1];
		y[i]=BL[(read()-1+lastans)%n+1];
		p[++t1]=x[i];p[++t1]=y[i];
	}
	sort(p+1,p+t1+1,cmp);t1=unique(p+1,p+t1+1)-p-1;t2=P=0;
	for(int i=1,j=1;i<=t1;i=j){
		while(j<=t1&&root[p[i]]==root[p[j]])++j;vT(i,j);
	}
	cnt=1;Time=BCC=tot=0;
	for(int i=1;i<=t1;++i)t[++P]=p[i];
	sort(t+1,t+P+1);P=unique(t+1,t+P+1)-t-1;
	for(int i=1;i<=t1;++i)h[p[i]]=bl[p[i]]=dfn[p[i]]=0;
	for(int i=1;i<=P;++i)h[t[i]]=bl[t[i]]=dfn[t[i]]=0;
	for(int i=1;i<=K;++i){
		add(x[i],y[i]);add(y[i],x[i]);
	}
	for(int i=1;i<=t2;++i){
		add(q[i].x,q[i].y);
		add(q[i].y,q[i].x);
	}
	for(int i=1;i<=P;++i){
		if(!dfn[t[i]])tarjan(t[i],0);
	}
	int opt=1;
	for(int i=2;i<=L;++i){
		if(bl[tmp[i]]!=bl[tmp[i-1]]){
			opt=0;break;
		}
	}
	lastans=(lastans+opt*id)%n;
	puts(opt?"YES":"NO");
}
int main(){
//	system("fc wwt.out wwt9.out");
//	freopen("wwt9.in","r",stdin);
//	freopen("wwt.out","w",stdout);
	n=read();m=read();Q=read();
	for(int i=1;i<=m;++i){
		x[i]=read();y[i]=read();
		add(x[i],y[i]);add(y[i],x[i]);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])tarjan(i,0);
	}
	for(int i=1;i<=n;++i)BL[i]=bl[i];
	memset(h,0,sizeof(h));cnt=0;
	for(int i=1;i<=m;++i){
		if(bl[x[i]]!=bl[y[i]]){
			add(bl[x[i]],bl[y[i]]);
			add(bl[y[i]],bl[x[i]]);
		}
	}
	Time=0;memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=BCC;++i){
		if(!dfn[i]){dfs1(i,i);dfs2(i,i);}
	}
	for(int i=1;i<=n;++i)DFN[i]=dfn[i];
	for(int i=1;i<=Q;++i)solve(i);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,cnt;
#define Maxn 1505

namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

struct Node{
	int siz,son[2];
	Node(){siz=son[0]=son[1]=0;}
	Node(int _siz,int _son0,int _son1){siz=_siz;son[0]=_son0;son[1]=_son1;} 
}tree[Maxn<<1];

struct Edge{
	int s,e,t;
	Edge(){s=e=t=0;}
	Edge(int _s,int _e,int _t){s=_s;e=_e;t=_t;}
	bool operator <(const Edge &z)const{return t<z.t;}
}edge[1200010];int ed=0;

int nodecnt[Maxn],edgecnt[Maxn],bel[Maxn],fa[Maxn];
int getroot(int x){
	if(fa[x]!=x)fa[x]=getroot(fa[x]);
	return fa[x];
}
int F[Maxn<<1][Maxn],sum[Maxn<<1];

#define ls tree[u].son[0]
#define rs tree[u].son[1]
void dfs(int u){
	if(u<=n){
		sum[u]=1;
		F[u][1]=1;
		return;
	}
	dfs(tree[u].son[0]);
	dfs(tree[u].son[1]);
	sum[u]=sum[ls]+sum[rs];
	if(tree[u].siz)F[u][1]=add(F[u][1],1);
	for(int i=1;i<=sum[ls];++i)
		for(int j=1;j<=sum[rs];++j)
			F[u][i+j]=add(F[u][i+j],mul(F[ls][i],F[rs][j]));
}

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	rd(n);cnt=n;int val;
	for(int i=1;i<=n;++i)tree[i].siz=1;
	for(int i=1;i<=n;++i){
		fa[i]=i;nodecnt[i]=1;edgecnt[i]=0;bel[i]=i;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			rd(val);
			if(i<j)edge[++ed]=Edge(i,j,val); 
		}
	}
	sort(edge+1,edge+ed+1);
	for(int i=1;i<=ed;++i){
		int x=edge[i].s,y=edge[i].e;
		x=getroot(x);
		y=getroot(y);
		if(x==y){
			edgecnt[x]++;
			if(edgecnt[x]==nodecnt[x]*(nodecnt[x]-1)/2)tree[bel[x]].siz=nodecnt[x];
		}else{
			edgecnt[x]+=edgecnt[y];nodecnt[x]+=nodecnt[y];edgecnt[x]++;
			cnt++;tree[cnt]=Node(0,bel[x],bel[y]);bel[x]=cnt;fa[y]=x;
			if(edgecnt[x]==nodecnt[x]*(nodecnt[x]-1)/2)tree[cnt].siz=2;
		}
	}
	dfs(cnt);
	for(int i=1;i<=n;++i)printf("%d ",F[cnt][i]);
	return 0;
}
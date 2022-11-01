#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define For(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int NN=500005; 

char s[NN],*Beg[NN],*End[NN],*cur=s;
int n,Be[NN],Q,tot,N,dfn[NN];
struct node{
	node *sn[26],*f;
}po[NN],*Cur=po,*rt;
int Que[NN],l,r;
long long ans[NN];
struct edge{
	int u,v,pre;
}e[NN]; int adj[NN],dex;
struct No{
	int x,v,Id,k;
	inline bool operator <(const No &A)const{
		return x<A.x;
	}
}ques[2000005];

void Pus(char *&u,char *&v){
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	u=cur+1; v=cur; node *p=rt;
	while(ch>='a' && ch<='z'){
		*(++cur)=ch; 
		node *&w=p->sn[ch-'a'];
		if(!w) w=++Cur;
		v=cur;
		Be[v-s]=w-po;
		p=w;
		ch=getchar();
	}
}

void bfs(){
	Que[l=r=1]=1;
	for(;l<=r;l++){
		int u=Que[l];
		for(int i=0;i<26;i++){
			node *v=(po+u)->sn[i];
			if(!v) continue;
			Que[++r]=v-po;
			node *w=(po+u)->f;
			while(w&&!w->sn[i])w=w->f;
			if(!w) v->f=rt;
			else v->f=w->sn[i];
		}
	}
	N=Cur-po;
	for(int i=2;i<=N;i++){
		int u=i,v=(po+i)->f-po;
		e[++dex]=(edge){v,u,adj[v]}; adj[v]=dex;
	}
}

int TOT,st[200005],ed[200005];
void dfs(int x){
	st[x]=++TOT;
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v;
		dfs(v);
	} ed[x]=TOT;
}

long long t[200005];
void Mod(int x){
//	printf("jia %d\n",x);
	for(int p=x;p<=N;p+=p&(-p)) t[p]++;
}

long long Ask(int x){
//	printf("wen %d\n",x);
	long long A=0;
	for(int p=x;p;p-=p&(-p)) A+=t[p];
	return A;
}

int main(){
	scanf("%d%d",&n,&Q);
	rt=++Cur;
	For(i,1,n) Pus(Beg[i],End[i]);
	bfs();
	dfs(1);
	for(int i=1;i<=Q;i++){
		int l,r,v;
		scanf("%d%d%d",&l,&r,&v);
		ques[++tot]=(No){r,v,i,1};
		ques[++tot]=(No){l-1,v,i,-1};
	}
	sort(ques+1,ques+tot+1);
	for(int i=1,now=1;i<=tot;i++){
		for(;ques[i].x>=now && now<=n;now++)
			for(char *x=Beg[now];x<=End[now];x++) Mod(st[Be[x-s]]);
		int ux=Be[End[ques[i].v]-s];
		ans[ques[i].Id]+=ques[i].k*(Ask(ed[ux])-Ask(st[ux]-1));
	}
	for(int i=1;i<=Q;i++) printf("%I64d\n",ans[i]);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 1500005
#define seed 23333
#define Mo 998244353
#define inf 1000000000
#define For(i,x,y) for(int i=(int)x;i<=(int)y;i++)
#define PII pair<int,int>
using namespace std;

inline int IN(){
	char ch=getchar(); int x=0,f=0;
	for(;ch<48||ch>57;ch=getchar()) f=(ch=='-');
	for(;ch>=48&&ch<=57;ch=getchar()) x=x*10+ch-48;
	return f?(-x):x;
}

int w[N],ned;
struct node{
	node *s[2],*f;
	int rev,mi,va;
	int dir(){return f->s[1]==this;}
	int isr(){return !f||(f->s[0]!=this&&f->s[1]!=this);}
	void set(node *c,int d){s[d]=c;if(c)c->f=this;}
	void rot(){
		node *y=f; int d=dir();
		if(!y->f) f=NULL;else{
			if(y->f->s[0]==y) y->f->s[0]=this;
			if(y->f->s[1]==y) y->f->s[1]=this;
			f=y->f;
		}
		y->set(s[!d],d);
		set(y,!d);
		y->upd();
	}
	void sep(){
		if(rev) For(i,0,1)if(s[i]) s[i]->rever();
		rev=0;
	}
	void upd(){
		mi=va;
		For(i,0,1) if(s[i]&&w[s[i]->mi]<w[mi]) mi=s[i]->mi;
	}
	void rever(){
		rev^=1;
		swap(s[0],s[1]);
	}
}E[N],*C=E,*stk[N],*rt;
int top,n;

void splay(node *w){
	for(node *k=w;;k=k->f){
		stk[++top]=k;
		if(k->isr()) break;
	}
	for(;top;top--) stk[top]->sep();
	while(!w->isr()){
		node *v=w->f;
		if(v->isr()){w->rot();break;}
		(w->dir()==v->dir())?(v->rot()):(w->rot());
		w->rot();
	} w->upd();
}

void access(node *w){
	node *y=NULL;
	for(;w;w=w->f){
		splay(w);
		w->set(y,1);
		w->upd();
		y=w;
	}
}

void evert(node *u){
	access(u),splay(u),u->rever();
}

map<PII,int>mps;
struct edge{
	int v,pre,ind;
}e[N];int dex,adj[N];
int tiao[N];

void DFS(int x,int ff=0)
{
	for(int i=adj[x];i;i=e[i].pre)
	{
		int v=e[i].v,d=e[i].ind;
		if(v==ff)continue;
		int p=mps[mk(x,v)];
		if(!p) p=mps[mk(v,x)];
		if(p)
		{
			ned--;
			tiao[p]=1;
			w[d]=inf+n+d;
			E[n+d].va=d;
		}else
		{
			w[d]=d;
			E[n+d].va=d;
		}
		E[v].f=E+n+d;
		E[n+d].f=E+x;
		DFS(v,x);
	}
}

int ue[N],ve[N];
void cut(node *u,node *v)
{
	evert(u),access(u),splay(v);
	v->f=NULL;
}

void cut(int u)
{
	cut(E+ue[u],E+n+u);
	cut(E+n+u,E+ve[u]);
}

void lin(node *u,node *v)
{
	evert(u),evert(v);
	u->f=v;
}

void lin(int u)
{
	lin(E+ue[u],E+n+u);
	lin(E+n+u,E+ve[u]);
}

int main()
{
	scanf("%d",&n);
	For(i,1,n-1)
	{
		int u=IN(),v=IN();
		ue[i]=u,ve[i]=v;
		e[++dex]=(edge){v,adj[u],i};adj[u]=dex;
		e[++dex]=(edge){u,adj[v],i};adj[v]=dex;
	}
	For(i,1,n-1)
	{
		int u=IN(),v=IN();
		ue[n-1+i]=u,ve[n-1+i]=v;
		mps[mk(u,v)]=i;
	}
	ned=n-1;
	DFS(1);
	w[0]=inf*2;
	For(i,1,n) E[i].va=0;
	For(i,1,2*n-1) E[i].upd();
	printf("%d\n",ned);
	For(i,1,n-1)
	{
		if(tiao[i])continue;
		int u=ue[n+i-1],v=ve[n+i-1];
		evert(E+u),access(E+v),splay(E+v);
		int tmi=E[v].mi;
//		printf("%d\n",tmi);
		E[n+n+i-1].va=n+i-1,w[n+i-1]=inf+n+i-1,E[n+n+i-1].upd();
		cut(tmi);
		lin(n+i-1);
		printf("%d %d %d %d\n",ue[tmi],ve[tmi],ue[n+i-1],ve[n+i-1]);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#define MN 100000
#define Sz(x) (x?x->sz:0) 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];
int size[MN+5],p[MN+5],c[MN+5][26],n,cnt,f[MN+5];
struct Heap{Heap*l,*r;int x,sz,val;
	Heap(int k):x(k){l=r=NULL;sz=1;val=0;}
	void Mark(int v){x+=v;val+=v;}
}*rt[MN+5];
void pushdown(Heap*x){if(x->l)x->l->Mark(x->val);if(x->r)x->r->Mark(x->val);x->val=0;}
Heap*Merge(Heap*x,Heap*y)
{
	if(!x) return y;if(!y) return x;
	if(x->x<y->x) swap(x,y);
	pushdown(x);x->r=Merge(x->r,y);
	if(Sz(x->l)<Sz(x->r)) swap(x->l,x->r);
	x->sz=Sz(x->l)+Sz(x->r)+1;
	return x;
}
long long ans;
void dfs(int x)
{
	size[x]=0;
	for(int i=0;i<26;++i) if(c[x][i]) 
		dfs(c[x][i]),rt[x]=Merge(rt[x],rt[c[x][i]]),size[x]+=size[c[x][i]];
	ans+=size[x]; 
//	cout<<x<<" "<<size[x]<<endl;
	if(p[x]) {if(rt[x]) rt[x]->Mark(1);}
	else
	{
		int s=rt[x]->x;ans-=s;
		pushdown(rt[x]);rt[x]=Merge(rt[x]->l,rt[x]->r);
		if(rt[x]) rt[x]->Mark(1);
	}
	rt[x]=Merge(rt[x],new Heap(1));
	size[x]+=p[x];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",st+1);int x=0;
		for(int j=1;st[j];++j) 
		{
			if(!c[x][st[j]-'a']) c[x][st[j]-'a']=++cnt;
			x=c[x][st[j]-'a'];
		}
		p[x]=1;
	}
	p[0]=1;dfs(0);cout<<ans;
	return 0;
}
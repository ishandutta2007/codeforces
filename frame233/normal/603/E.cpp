// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=300005;
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val==o.val?id<o.id:val<o.val;
	}
	Finline bool operator == (const node &o)const
	{
		return val==o.val&&id==o.id;
	}
};
int E[N+2][2];
int ew[N+1];
int cnt;
int n;
struct heap{
	std::priority_queue<node> q1,q2;
	Finline void push(const node &o)
	{
		q1.push(o);
	}
	Finline void pop(const node &o)
	{
		q2.push(o);
	}
	Finline node top()
	{
		while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
}q;
struct LCT{
	struct Node{
		int ch[2],fa;
		int siz,tmp;
		bool rev;
		int val;
	}f[N<<1];
	Finline void PushUp(int x)
	{
		f[x].siz=f[f[x].ch[0]].siz+f[f[x].ch[1]].siz+f[x].tmp;
		f[x].val=x>n?x-n:0;
		if(ew[f[f[x].ch[0]].val]>ew[f[x].val]) f[x].val=f[f[x].ch[0]].val;
		if(ew[f[f[x].ch[1]].val]>ew[f[x].val]) f[x].val=f[f[x].ch[1]].val;
	}
	Finline int iden(int x)
	{
		return f[f[x].fa].ch[1]==x;
	}
	Finline int nroot(int x)
	{
		return f[f[x].fa].ch[0]==x||f[f[x].fa].ch[1]==x;
	}
	Finline void flip(int x)
	{
		std::swap(f[x].ch[0],f[x].ch[1]);
		f[x].rev^=1;
	}
	Finline void PushDown(int x)
	{
		if(f[x].rev)
		{
			flip(f[x].ch[0]);
			flip(f[x].ch[1]);
			f[x].rev=false;
		}
	}
	Finline void rotate(int x)
	{
		int y=f[x].fa,z=f[y].fa,k=iden(x),w=f[x].ch[k^1];
		if(nroot(y)) f[z].ch[iden(y)]=x;
		f[x].ch[k^1]=y,f[y].ch[k]=w;
		f[x].fa=z,f[y].fa=x;
		if(w) f[w].fa=y;
		PushUp(y),PushUp(x);
	}
	void splay(int x)
	{
		static int st[N+3];
		int top=1,y;
		st[top]=y=x;
		while(nroot(y)) st[++top]=y=f[y].fa;
		while(top) PushDown(st[top--]);
		while(nroot(x))
		{
			y=f[x].fa;
			if(nroot(y)) rotate(iden(x)==iden(y)?y:x);
			rotate(x);
		}
	}
	void access(int x)
	{
		for(int y=0;x;x=f[y=x].fa)
		{
			splay(x);
			f[x].tmp+=f[f[x].ch[1]].siz;
			f[x].ch[1]=y;
			f[x].tmp-=f[y].siz;
			PushUp(x);
		}
	}
	Finline void makeroot(int x)
	{
		access(x);
		splay(x);
		flip(x);
	}
	int findroot(int x)
	{
		access(x);
		splay(x);
		while(f[x].ch[0])
		{
			PushDown(x);
			x=f[x].ch[0];
		}
		splay(x);
		return x;
	}
	Finline void split(int x,int y)
	{
		makeroot(x);
		access(y);
		splay(y);
	}
	Finline void link(int x,int y)
	{
		makeroot(x);
		makeroot(y);
		f[x].fa=y;
		f[y].tmp+=f[x].siz;
		PushUp(y);
		splay(y);
	}
	Finline void cut(int x,int y)
	{
		split(x,y);
		f[x].fa=0;
		f[y].ch[0]=0;
		PushUp(y);
		splay(y);
	}
	Finline int getsize(int x)
	{
		access(x);
		splay(x);
		return f[x].siz;
	}
	Finline int getedge(int x,int y)
	{
		split(x,y);
		return f[y].val;
	}
	Finline void addedge(int x,int y,int id)
	{
		if(findroot(x)==findroot(y))
		{
			int qwq=getedge(x,y);
			if(ew[qwq]>ew[id])
			{
				cut(E[qwq][0],qwq+n);
				cut(qwq+n,E[qwq][1]);
				q.pop((node){ew[qwq],qwq});
				link(x,id+n);
				link(id+n,y);
				q.push((node){ew[id],id});
			}
		}
		else
		{
			if((getsize(x)&1)&&(getsize(y)&1)) cnt-=2;
			link(x,id+n);
			link(id+n,y);
			q.push((node){ew[id],id});
		}
	}
	Finline bool check()
	{
		node x=q.top();
		q.pop(x);
		int a=E[x.id][0],b=E[x.id][1];
		cnt-=(getsize(a)&1);
		cut(a,x.id+n);
		cut(x.id+n,b);
		cnt+=(getsize(a)&1);
		cnt+=(getsize(b)&1);
		if(!cnt) return true;
		cnt=0;
		link(a,x.id+n);
		link(b,x.id+n);
		q.push(x);
		return false;
	}
}tr;
int main()
{
	int m;
	read(n,m);
	int x,y,w;
	cnt=n;
	for(int i=1;i<=n;++i)
	{
		tr.f[i].siz=tr.f[i].tmp=1;
		tr.f[i].val=0;
	}
	for(int i=1;i<=m;++i)
	{
		read(x,y,w);
		ew[i]=w;
		E[i][0]=x,E[i][1]=y;
		tr.addedge(x,y,i);
		if(!cnt)
		{
			while(tr.check());
			printf("%d\n",q.top().val);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 200001
#define M 15000001
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int top,st[N],pre[N],nxt[N];
int n,q,len[N],val[N];
char *s[N],mem[N],*last;
int lcp(int i,int j)
{
	int k;
	for(k=1;k<=min(len[i],len[j])&&s[i][k]==s[j][k];++k);
	return k-1;
}
namespace seg
{
	struct node
	{
		int mx,ml,mr,siz;
		node(int _mx=0,int _ml=0,int _mr=0,int _siz=0)
		:mx(_mx),ml(_ml),mr(_mr),siz(_siz){}
		node operator + (const node &i)const
		{
			return node(max(mr+i.ml,max(mx,i.mx)),ml==siz?ml+i.ml:ml,
			i.mr==i.siz?i.mr+mr:i.mr,siz+i.siz);
		}
	}e[M];
	int sz,root[101],ls[M],rs[M];
	void modify(int &x,int l,int r,int a)
	{
		if(!x)x=++sz,e[x].siz=r-l+1;
		if(l==r)
		{
			if(e[x].mx)e[x].mx=e[x].ml=e[x].mr=0;
			else e[x].mx=e[x].ml=e[x].mr=1;
			return;
		}
		int m=l+r>>1;
		if(a<=m)modify(ls[x],l,m,a);
		else modify(rs[x],m+1,r,a);
		e[ls[x]].siz=m-l+1;e[rs[x]].siz=r-m;
		e[x]=e[ls[x]]+e[rs[x]];
	}
	node query(int x,int l,int r,int a,int b)
	{
		if(!x)return node(0,0,0,r-l+1);
		if(a<=l && b>=r)return e[x];
		int m=l+r>>1;
		if(b<=m)return query(ls[x],l,m,a,b);
		else if(a>m)return query(rs[x],m+1,r,a,b);
		else return query(ls[x],l,m,a,b)+query(rs[x],m+1,r,a,b);
	}
}
namespace seg2
{
	int l[1<<18],r[1<<18],mx[1<<18];
	void upd(int k){mx[k]=max(mx[k<<1],mx[k<<1|1]);}
	void build(int k,int a,int b)
	{
		l[k]=a;r[k]=b;
		if(a==b)
		{
			mx[k]=len[a];
			return;
		}
		build(k<<1,a,a+b>>1);
		build(k<<1|1,(a+b>>1)+1,b);
		upd(k);
	}
	void modify(int k,int a)
	{
		if(l[k]==r[k])
		{
			mx[k]=len[a];
			return;
		}
		if(a<=l[k]+r[k]>>1)modify(k<<1,a);
		else modify(k<<1|1,a);
		upd(k);
	}
	int query(int k,int a,int b)
	{
		if(a>r[k] || b<l[k])return 0;
		if(a<=l[k] && b>=r[k])return mx[k];
		return max(query(k<<1,a,b),query(k<<1|1,a,b));
	}
}
void solve()
{
	static int topp,stt[N];
	for(int i=1;i<=top;)
	{
		int j=i;
		while(j<top && st[j]+1==st[j+1])++j;
		topp=0;
		for(int k=i;k<=j;++k)
		{
			while(topp && val[stt[topp]]>=val[st[k]])--topp;
			if(topp)pre[k]=stt[topp];
			else pre[k]=st[i]-1;
			stt[++topp]=st[k];
		}
		topp=0;
		for(int k=j;k>=i;--k)
		{
			while(topp && val[stt[topp]]>=val[st[k]])--topp;
			if(topp)nxt[k]=stt[topp];
			else nxt[k]=st[j]+1;
			stt[++topp]=st[k];
		}
		i=j+1;
	}
}
void del(int x)
{
	int pos;
	for(int i=1;i<=top;++i)
		if(st[i]==x)
			pos=i;
	--top;
	for(int i=pos;i<=top;++i)
		st[i]=st[i+1];
}
void ins(int x)
{
	st[++top]=x;
	for(int i=top;i;--i)
		if(st[i]<st[i-1])
			swap(st[i],st[i-1]);
}
int main()
{
	re(n),re(q);
	s[0]=mem;
	using namespace seg;
	for(int i=1;i<=n;++i)
	{
		s[i]=s[i-1]+len[i-1];
		scanf("%s",s[i]+1);
		len[i]=strlen(s[i]+1);
		val[i]=lcp(i-1,i);
		for(int j=1;j<=min(val[i],75);++j)
			modify(root[j],1,n,i);
		if(val[i]>75)st[++top]=i;
	}
	seg2::build(1,1,n);
	last=s[n]+len[n];
	solve();
	for(int opt,a,b;q--;)
	{
		re(opt),re(a);
		if(opt==1)
		{
			re(b);
			if(a==b)
			{
				printf("%d\n",len[a]);
				continue;
			}
			int ans=seg2::query(1,a,b);
			++a;
			for(int i=1,x;i<=75;++i)
			{
				x=query(root[i],1,n,a,b).mx;
				if(x)ans=max(ans,i*(x+1));
			}
			for(int i=1,x;i<=top;++i)if(st[i]>=a && st[i]<=b)
			{
				x=min(nxt[i]-1,b)-max(pre[i],a-1);
				if(x)ans=max(ans,val[st[i]]*(x+1));
			}
			printf("%d\n",ans);
		}
		else
		{
			for(int i=1;i<=min(val[a],75);++i)
				modify(root[i],1,n,a);
			if(val[a]>75)del(a);
			for(int i=1;i<=min(val[a+1],75);++i)
				modify(root[i],1,n,a+1);
			if(val[a+1]>75)del(a+1);

			s[a]=last;
			scanf("%s",s[a]+1);
			len[a]=strlen(s[a]+1);
			seg2::modify(1,a);
			last+=len[a];
			val[a]=lcp(a,a-1);
			val[a+1]=lcp(a+1,a);

			for(int i=1;i<=min(val[a],75);++i)
				modify(root[i],1,n,a);
			if(val[a]>75)ins(a);
			for(int i=1;i<=min(val[a+1],75);++i)
				modify(root[i],1,n,a+1);
			if(val[a+1]>75)ins(a+1);

			solve();
		}
	}
}
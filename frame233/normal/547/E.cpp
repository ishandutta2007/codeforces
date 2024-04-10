// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
char ibuf[1<<21],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
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
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}
char obuf[1<<24],buf[21],*T=obuf,*Q=buf;
template <typename _Tp>Finline void print(_Tp u,char ch='\n')
{
	if(!u) *T++=48;
	else
	{
		if(u<0) u=-u,*T++='-';
		while(u) *Q++=u%10+48,u/=10;
		while(Q!=buf) *T++=*--Q;
	}
	*T++=ch;
}

const int N=400005;
struct seg_tr{
	struct Node{
		int ls,rs;
		ll sum;
	}f[N*25];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	void Update(int &cur,int l,int r,int pos)
	{
		if(!cur) cur=++node_cnt;
		if(l==r)
		{
			++f[cur].sum;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(f[cur].ls,l,mid,pos);
		else Update(f[cur].rs,mid+1,r,pos);
		PushUp(cur);
	}
	ll Query(int L,int R,int l,int r,int cur)
	{
		if(!cur) return 0;
		if(L<=l&&r<=R)
		{
			return f[cur].sum;
		}
		int mid=(l+r)>>1;
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
	int merge(int a,int b,int l,int r)
	{
		if(!a||!b) return a|b;
		if(l==r)
		{
			f[a].sum+=f[b].sum;
			return a;
		}
		int mid=(l+r)>>1;
		f[a].ls=merge(f[a].ls,f[b].ls,l,mid);
		f[a].rs=merge(f[a].rs,f[b].rs,mid+1,r);
		PushUp(a);
		return a;
	}
}tr;
int root[N];
int n;
struct node{
	int l,r,id;
};
ll ans[N<<1];
std::vector<node> v[N];
int pos[N];
struct SAM{
	struct Node{
		int ch[26];
		int fa,len;
	}f[N];
	int node_cnt,last;
	Finline SAM():node_cnt(1),last(1){}
	void insert(int c,int id)
	{
		if(f[last].ch[c])
		{
			int p=last;
			int q=f[p].ch[c];
			if(f[q].len==f[p].len+1)
			{
				last=f[last].ch[c];
			}
			else
			{
				int clone=++node_cnt;
				memcpy(f[clone].ch,f[q].ch,104);
				f[clone].fa=f[q].fa;
				f[clone].len=f[p].len+1;
				f[q].fa=clone;
				while(p&&f[p].ch[c]==q)
				{
					f[p].ch[c]=clone;
					p=f[p].fa;
				}
				last=clone;
			}
			tr.Update(root[last],1,n,id);
			pos[id]=last;
			return;
		}
		int cur=++node_cnt;
		pos[id]=cur;
		tr.Update(root[cur],1,n,id);
		f[cur].len=f[last].len+1; 
		int p=last;
		while(p&&!f[p].ch[c])
		{
			f[p].ch[c]=cur;
			p=f[p].fa;
		}
		if(!p)
		{
			f[cur].fa=1;
		}
		else
		{
			int q=f[p].ch[c];
			if(f[q].len==f[p].len+1)
			{
				f[cur].fa=q;
			}
			else
			{
				int clone=++node_cnt;
				memcpy(f[clone].ch,f[q].ch,104);
				f[clone].fa=f[q].fa;
				f[clone].len=f[p].len+1;
				f[cur].fa=f[q].fa=clone;
				while(p&&f[p].ch[c]==q)
				{
					f[p].ch[c]=clone;
					p=f[p].fa;
				}
			}
		}
		last=cur;
	}
	void solve()
	{
		int maxx=0;
		for(int i=1;i<=node_cnt;++i) chmax(maxx,f[i].len);
		static int tax[N],A[N];
		memset(tax,0,4*(maxx+3));
		for(int i=1;i<=node_cnt;++i) ++tax[f[i].len];
		for(int i=1;i<=maxx;++i) tax[i]+=tax[i-1];
		for(int i=1;i<=node_cnt;++i) A[tax[f[i].len]--]=i;
		for(int i=node_cnt;i>1;--i)
		{
			for(auto it:v[A[i]])
			{
				ans[it.id]=tr.Query(it.l,it.r,1,n,root[A[i]]);
			}
			root[f[A[i]].fa]=tr.merge(root[f[A[i]].fa],root[A[i]],1,n);
		}
	}
}sam;
char s[N];
int main()
{
	int _;
	read(n,_);
	for(int i=1;i<=n;++i)
	{
		sam.last=1;
		int len=read_str(s+1);
		for(int j=1;j<=len;++j)
		{
			sam.insert(s[j]-97,i);
		}
	}
	int l,r,k;
	for(int i=1;i<=_;++i)
	{
		read(l,r,k);
		v[pos[k]].push_back({l,r,i});
	}
	sam.solve();
	for(int i=1;i<=_;++i) print(ans[i]);
	return fwrite(obuf,1,T-obuf,stdout),0;
}
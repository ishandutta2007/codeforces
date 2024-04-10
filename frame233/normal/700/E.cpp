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

const int N=400005;
struct seg_tr{
	struct Node{
		int ls,rs;
		bool val;
	}f[N<<5];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=f[f[x].ls].val|f[f[x].rs].val;
	}
	void Update(int &cur,int l,int r,int pos)
	{
		if(!cur)
		{
			cur=++node_cnt;
		}
		if(l==r)
		{
			f[cur].val=1;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(f[cur].ls,l,mid,pos);
		else Update(f[cur].rs,mid+1,r,pos);
		PushUp(cur);
	}
	bool Query(int L,int R,int l,int r,int cur)
	{
		if(!cur)
		{
			return false;
		}
		if(L<=l&&r<=R)
		{
			return f[cur].val;
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			return Query(L,R,l,mid,f[cur].ls)||Query(L,R,mid+1,r,f[cur].rs);
		}
		if(L<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls);
		}
		return Query(L,R,mid+1,r,f[cur].rs);
	}
	int merge(int a,int b,int l,int r)
	{
		if(!a||!b) return a|b;
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].val=f[a].val|f[b].val;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=merge(f[a].ls,f[b].ls,l,mid);
		f[cur].rs=merge(f[a].rs,f[b].rs,mid+1,r);
		PushUp(cur);
		return cur;
	}
}tr;
int root[N];
int n;
struct SAM{
	struct Node{
		int fa,len;
		int ch[26];
	}f[N];
	int node_cnt,last;
	Finline SAM():node_cnt(1),last(1){};
	int pos[N];
	void insert(int c,int id)
	{
		int cur=++node_cnt;
		f[cur].len=f[last].len+1;
		dp[cur]=1;
		pos[cur]=id;
		tr.Update(root[cur],1,n,id);
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
	int dp[N];
	int pre[N];
	int Dp()
	{
		int maxx=0;
		for(int i=1;i<=node_cnt;++i) chmax(maxx,f[i].len);
		static int tax[N],A[N];
		memset(tax,0,(maxx+3)<<2);
		for(int i=1;i<=node_cnt;++i) ++tax[f[i].len];
		for(int i=1;i<=maxx;++i) tax[i]+=tax[i-1];
		for(int i=1;i<=node_cnt;++i) A[tax[f[i].len]--]=i;
		for(int i=node_cnt;i>1;--i)
		{
			root[f[A[i]].fa]=tr.merge(root[f[A[i]].fa],root[A[i]],1,n);
			pos[f[A[i]].fa]=pos[A[i]];
		}
		int ans=0;
		for(int i=2;i<=node_cnt;++i)
		{
			int cur=A[i];
			int fa=f[cur].fa;
			if(fa==1||(max(1,pos[cur]-f[cur].len+f[pre[fa]].len)<pos[cur]&&tr.Query(max(1,pos[cur]-f[cur].len+f[pre[fa]].len),pos[cur]-1,1,n,root[pre[fa]])))
			{
				dp[cur]=dp[fa]+1;
				pre[cur]=cur;
			}
			else
			{
				dp[cur]=dp[fa];
				pre[cur]=pre[fa];
			}
			chmax(ans,dp[cur]);
		}
		return ans;
	}
}sam;
char s[N];
int main()
{
    read(n);
	n=read_str(s+1);
	for(int i=1;i<=n;++i)
	{
		sam.insert(s[i]-97,i);
	}
	printf("%d\n",sam.Dp());
	return 0;
}
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

const int N=600205;
char *s[N];
int len[N];
char t[N];
int tax[N],A[N];
struct node{
	int len,val;
	Finline bool operator < (const node &o)const
	{
		return len<o.len;
	}
};
struct SAM{
	struct Node{
		int fa,len;
		int ch[26];
		std::vector<node> v;
	};
	Node *f;
	int *dp,*g;
	int node_cnt,last;
	Finline SAM():f(NULL),dp(NULL),g(NULL){}
	Finline void init(int size)
	{
		node_cnt=1,last=1;
		f=(Node *)calloc((size<<1)+5,sizeof(Node));
		dp=(int *)calloc((size<<1)+5,4);
		g=(int *)calloc((size<<1)+5,4);
	}
	Finline void clear()
	{
		free(f);
		free(dp);
		free(g);
		f=NULL,dp=NULL,g=NULL;
	}
	void insert(int c,int val)
	{
		if(f[last].ch[c])
		{
			int q=f[last].ch[c];
			if(f[q].len==f[last].len+1)
			{
				last=q;
				if(val)
				{
					if(val>0)
					{
						++dp[last];
						++g[last];
						f[last].v.push_back({val,1});
					}
					else
					{
						--dp[last];
						--g[last];
						f[last].v.push_back({-val,-1});
					}
				}
				return;
			}
			int clone=++node_cnt;
			memcpy(f[clone].ch,f[q].ch,104);
			f[clone].fa=f[q].fa;
			f[clone].len=f[last].len+1;
			f[q].fa=clone;
			while(last&&f[last].ch[c]==q)
			{
				f[last].ch[c]=clone;
				last=f[last].fa;
			}
			last=clone;
			if(val)
			{
				if(val>0)
				{
					++dp[last];
					++g[last];
					f[last].v.push_back({val,1});
				}
				else
				{
					--dp[last];
					--g[last];
					f[last].v.push_back({-val,-1});
				}
			}
			return;
		}
		int cur=++node_cnt;
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
		if(val)
		{
			if(val>0)
			{
				++dp[last];
				++g[last];
				f[last].v.push_back({val,1});
			}
			else
			{
				--dp[last];
				--g[last];
				f[last].v.push_back({-val,-1});
			}
		}
	}
	void build()
	{
		int maxx=0;
		for(int i=1;i<=node_cnt;++i)
		{
			chmax(maxx,f[i].len);
		}
		memset(tax,0,(maxx+3)<<2);
		for(int i=1;i<=node_cnt;++i)
		{
			++tax[f[i].len];
		}
		for(int i=1;i<=maxx;++i)
		{
			tax[i]+=tax[i-1];
		}
		for(int i=1;i<=node_cnt;++i)
		{
			A[tax[f[i].len]--]=i;
		}
		for(int i=1;i<=node_cnt;++i)
		{
			dp[A[i]]+=dp[f[A[i]].fa];
		}
		for(int i=1;i<=node_cnt;++i)
		{
			std::sort(f[i].v.begin(),f[i].v.end());
			for(int j=1;j<(int)f[i].v.size();++j)
			{
				f[i].v[j].val+=f[i].v[j-1].val;
			}
		}
	}
	int Query(char *t,int n)
	{
		int cur=1;
		int ans=0;
		int l=0;
		for(int i=1;i<=n;++i)
		{
			int tmp=t[i]-97;
			while(cur>1&&!f[cur].ch[tmp])
			{
				cur=f[cur].fa;
				l=f[cur].len;
			}
			if(f[cur].ch[tmp])
			{
				cur=f[cur].ch[tmp];
				++l;
			}
			ans+=dp[cur]-g[cur];
			std::vector<node>::iterator it=std::upper_bound(f[cur].v.begin(),f[cur].v.end(),(node){l,0});
			if(it!=f[cur].v.begin())
			{
				--it;
				ans+=it->val;
			}
		}
		return ans;
	}
}sam[21];
int v[N];
void ins(int id,int val)
{
	v[id]=val;
	int k=lowbit(id);
	int last=0;
	for(int i=0;(1<<i)<=k;++i)
	{
		if((id-1)&(1<<i))
		{
			sam[i].clear();
		}
		last=i;
	}
	int sum=0;
	for(int i=id-k+1;i<=id;++i)
	{
		sum+=len[i];
	}
	sam[last].init(sum);
	for(int i=id-k+1;i<=id;++i)
	{
		sam[last].last=1;
		for(int j=1;j<len[i];++j)
		{
			sam[last].insert(s[i][j]-97,0);
		}
		sam[last].insert(s[i][len[i]]-97,len[i]*v[i]);
	}
	sam[last].build();
}
int Qry(char *s,int n,int id)
{
	int ans=0;
	for(int i=0;i<=20;++i)
	{
		if((id>>i)&1)
		{
			ans+=sam[i].Query(s,n);
		}
	}
	return ans;
}
int main()
{
	int _;
	read(_);
	int opt;
	int cnt=0;
	for(int i=1;i<=_;++i)
	{
		read(opt);
		len[cnt+1]=read_str(t+1);
		if(opt==3)
		{
			printf("%d\n",Qry(t,len[cnt+1],cnt));
			fflush(stdout);
			continue;
		}
		++cnt;
		s[cnt]=(char *)malloc(len[cnt]+3);
		memcpy(s[cnt],t,len[cnt]+3);
		if(opt==1) ins(cnt,1);
		else ins(cnt,-1);
	}
	for(int i=1;i<=cnt;++i) free(s[i]);
	for(int i=0;i<=20;++i) sam[i].clear();
	return 0;
}
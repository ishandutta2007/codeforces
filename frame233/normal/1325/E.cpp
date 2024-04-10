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
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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

const int N=1000005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int p[N],pos;
int id[N];
bool pr[N];
void init(int n)
{
	p[pos=1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!pr[i])
		{
			p[++pos]=i;
			id[i]=pos;
		}
		for(int j=2;j<=pos&&i*p[j]<=n;++j)
		{
			pr[i*p[j]]=1;
			if(!(i%p[j]))
			{
				break;
			}
		}
	}
}
int calc(int &x,int p)
{
	int cnt=0;
	while(!(x%p)) x/=p,++cnt;
	return cnt&1;
}
bool used[N];
struct node{
	int u,d,fa;
};
node _q[N];
int _l,_r;
int dis1[N],dis2[N];
int main()
{
	init(N-1);
	int n;
	read(n);
	int x;
	bool flag=false;
	for(int i=1;i<=n;++i)
	{
		read(x);
		std::vector<int> qwq;
		for(int j=2;p[j]*p[j]<=x;++j)
		{
			if(!(x%p[j]))
			{
				int cnt=calc(x,p[j]);
				if(cnt&1) qwq.push_back(j);
			}
		}
		if(x>1) qwq.push_back(std::lower_bound(p+1,p+pos+1,x)-p);
		if(qwq.size()==0)
		{
			printf("1\n");
			return 0;
		}
		if(qwq.size()==1)
		{
			int tmp=qwq[0];
			if(used[p[tmp]])
			{
				flag=true;
			}
			used[p[tmp]]=true;
			add(1,tmp);
			add(tmp,1);
		}
		else
		{
			int u=qwq[0],v=qwq[1];
			if(used[p[u]*p[v]])
			{
				flag=true;
			}
			used[p[u]*p[v]]=true;
			add(u,v);
			add(v,u);
		}
	}
	if(flag)
	{
		printf("2\n");
		return 0;
	}
	int ans=inf;
	for(int i=1;i<=169;++i)
	{
		memset(dis1,255,(pos+3)<<2);
		memset(dis2,255,(pos+3)<<2);
		_q[_l=_r=1]={i,0,-1};
		dis1[i]=0;
		while(_l!=_r+1)
		{
			node x=_q[_l++];
			for(int i=front[x.u];i;i=c[i].nxt)
			{
				if(c[i].v==x.fa) continue;
				if(dis1[c[i].v]==-1)
				{
					dis1[c[i].v]=x.d+1;
					_q[++_r]=(node){c[i].v,dis1[c[i].v],x.u};
				}
				else if(dis2[c[i].v]==-1)
				{
					dis2[c[i].v]=x.d+1;
					_q[++_r]=(node){c[i].v,dis2[c[i].v],x.u};
				}
			}
		}
		for(int _=front[i];_;_=c[_].nxt)
		{
			if(dis2[c[_].v]>0)
			{
				chmin(ans,dis2[c[_].v]+1);
			}
		}
	}
	if(ans<inf)
	{
		printf("%d\n",ans);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
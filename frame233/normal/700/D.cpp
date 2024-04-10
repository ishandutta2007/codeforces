// luogu-judger-enable-o2
// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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

const int N=100005;
const int block=350;
struct qry{
	int l,r;
	int block,id;
	Finline bool operator < (const qry &o)const
	{
		return block==o.block?(block&1?r>o.r:r<o.r):block<o.block;
	}
}q[N];
int a[N];
int ans[N];
int cnt[N];
int ccnt[N];
int tmp[N];
int pos[N],P;
Finline void add(const int &x)
{
	--ccnt[cnt[x]];
	++cnt[x];
	++ccnt[cnt[x]];
}
Finline void del(const int &x)
{
	--ccnt[cnt[x]];
	--cnt[x];
	++ccnt[cnt[x]];
}
int calc()
{
	std::priority_queue<int,std::vector<int>,std::greater<int> > q;
	for(int i=1;i<=P;++i)
	{
		if(cnt[pos[i]]>block)
		{
			q.push(cnt[pos[i]]);
		}
	}
	for(int i=1;i<=block;++i)
	{
		tmp[i]=ccnt[i];
	}
	int last=0;
	int ans=0;
	for(int i=1;i<=block;++i)
	{
		if(tmp[i])
		{
			if(last)
			{
				--tmp[i];
				ans+=i+last;
				if(i+last>block) q.push(i+last);
				else ++tmp[i+last];
				last=0;
			}
			if(tmp[i]&1)
			{
				--tmp[i];
				last=i;
			}
			if(i<<1>block)
			{
				for(int j=1;j<=(tmp[i]>>1);++j)
				{
					q.push(i<<1);
					ans+=i<<1;
				}
			}
			else
			{
				tmp[i<<1]+=tmp[i]>>1;
				ans+=i*tmp[i];
			}
		}
	}
	if(last) q.push(last);
	while(!q.empty())
	{
		int x=q.top();
		q.pop();
		if(q.empty()) break;
		int y=q.top();
		q.pop();
		ans+=x+y;
		q.push(x+y);
	}
	return ans;
}
int main()
{
	int n,m;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		++tmp[a[i]];
	}
	for(int i=1;i<=100000;++i)
	{
		if(tmp[i]>block)
		{
			pos[++P]=i;
		}
	}
	read(m);
	for(int i=1;i<=m;++i)
	{
		read(q[i].l,q[i].r);
		q[i].block=q[i].l/block;
		q[i].id=i;
	}
	std::sort(q+1,q+m+1);
	int l=1,r=0;
	for(int i=1;i<=m;++i)
	{
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		ans[q[i].id]=calc();
	}
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
    return 0;
}
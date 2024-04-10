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

const int N=1005;
std::vector<std::pair<int,int> > ans;
std::vector<int> e[N];
bool mark[N][N];
Finline void add(int u,int v)
{
	if(mark[u][v]) return;
	mark[u][v]=mark[v][u]=1;
	e[u].pb(v);
	e[v].pb(u);
	ans.pb(mkpr(u,v));
}
std::bitset<N> B[N],tmp,cur;
int siz[N];
int main()
{
	int n;
	read(n);
	if(n==2)
	{
		printf("1 2\n");
		return 0;
	}
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(y);
		siz[i]=y;
		while(y--) read(x),B[i].set(x);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			tmp=B[i]&B[j];
			if(tmp.count()==2)
			{
				add(tmp._Find_first(),tmp._Find_next(tmp._Find_first()));
			}
		}
	}
	if(ans.empty())
	{
		for(int i=2;i<=n;++i) printf("1 %d\n",i);
		return 0;
	}
	if(SZ(ans)==1)
	{
		int a=ans.back().first;
		int b=ans.back().second;
		for(int i=1;i<=n;++i)
		{
			if(siz[i]!=n)
			{
				tmp=B[i];
				break;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(i==a||i==b) continue;
			if(tmp.test(i)) printf("%d %d\n",a,i);
			else printf("%d %d\n",b,i);
		}
		printf("%d %d\n",a,b);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		if(e[i].empty())
		{
			int minn=inf;
			for(int j=1;j<=n;++j)
			{
				if(B[j].test(i)&&siz[j]<minn)
				{
					cur=B[j];
					minn=siz[j];
				}
			}
			for(int j=1;j<=n;++j)
			{
				if(e[j].empty())
				{
					cur.reset(j);
				}
			}
			for(int j=1;j<=n;++j)
			{
				if(i!=j)
				{
					tmp.reset();
					for(auto it:e[j])
					{
						if(!e[it].empty())
						{
							tmp.set(it);
						}
					}
					if(!e[j].empty()) tmp.set(j);
					if(cur==tmp)
					{
						add(i,j);
						break;
					}
				}
			}
		}
	}
	fprintf(stderr,"size = %d\n",SZ(ans));
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
	return 0;
}
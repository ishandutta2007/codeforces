// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&((a=b),0);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct node{
	int st,cost,id;
	Finline bool operator < (const node &o)const{return cost<o.cost;}
};
struct NODE{
	int cost,id1,id2;
	Finline NODE(const int COST=Inf,const int Id1=0,const int Id2=0):cost(COST),id1(Id1),id2(Id2){}
	Finline bool operator < (const NODE &o)const{return cost<o.cost;}
	Finline bool operator > (const NODE &o)const{return cost>o.cost;}
}f[N];
int state[N];
std::vector<node> v[1025],a;
int main()
{
	int n,m,x,y;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read(y);
		while(y--)
		{
			read(x);
			state[i]|=(1<<(x-1));
		}
	}
	node tmp;
	for(int i=1;i<=m;++i)
	{
		read(tmp.cost,x);
		tmp.st=0;
		while(x--)
		{
			read(y);
			tmp.st|=(1<<(y-1));
		}
		tmp.id=i;
		v[tmp.st].push_back(tmp);
	}
	for(int i=0;i<1024;++i)
	{
		std::sort(v[i].begin(),v[i].end());
		for(int j=0;j<(int)v[i].size()&&j<2;++j)
		{
			a.push_back(v[i][j]);
		}
	}
	for(int i=0;i<(int)a.size();++i)
	{
		for(int j=i+1;j<(int)a.size();++j)
		{
			chmin(f[a[i].st|a[j].st],NODE(a[i].cost+a[j].cost,a[i].id,a[j].id));
		}
	}
	int ans=0,res=Inf,id1=0,id2=0;
	for(int i=0;i<1024;++i)
	{
		if(f[i].cost!=Inf)
		{
			int t1=0;
			for(int k=1;k<=n;++k)
			{
				if((i&state[k])==state[k])
				{
					++t1;
				}
			}
			if(t1>ans)
			{
				ans=t1,res=f[i].cost;
				id1=f[i].id1,id2=f[i].id2;
			}
			else if(t1==ans&&f[i].cost<=res)
			{
				res=f[i].cost;
				id1=f[i].id1,id2=f[i].id2;
			}
		}
	}
	printf("%d %d\n",id1,id2);
	return 0;
}
//
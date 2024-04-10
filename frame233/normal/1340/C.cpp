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

const int N=10005;
int d[N];
int n,m;
int dis[N][1005];
std::deque<std::pair<int,int> > q;
int main()
{
	read(n,m);
	for(int i=1;i<=m;++i)
	{
		read(d[i]);
	}
	int g,r;
	read(g,r);
	std::sort(d+1,d+m+1);
	memset(dis,63,sizeof(dis));
	dis[1][0]=0;
	q.pb(mkpr(1,0));
	while(!q.empty())
	{
		std::pair<int,int> x=q.front();
		q.pop_front();
		int i=x.first,j=x.second;
		if(i>1&&j+d[i]-d[i-1]<=g)
		{
			if(dis[i-1][j+d[i]-d[i-1]]>dis[i][j])
			{
				dis[i-1][j+d[i]-d[i-1]]=dis[i][j];
				q.push_front(std::make_pair(i-1,j+d[i]-d[i-1]));
			}
		}
		if(i<m&&j+d[i+1]-d[i]<=g)
		{
			if(dis[i+1][j+d[i+1]-d[i]]>dis[i][j])
			{
				dis[i+1][j+d[i+1]-d[i]]=dis[i][j];
				q.push_front(std::make_pair(i+1,j+d[i+1]-d[i]));
			}
		}
		if(j==g)
		{
			if(dis[i][0]>dis[i][g]+1)
			{
				dis[i][0]=dis[i][g]+1;
				q.push_back(std::make_pair(i,0));
			}
		}
	}
	ll ans=1e18;
	for(int i=0;i<=g;++i)
	{
		if(dis[m][i]<inf)
		{
			chmin(ans,1ll*dis[m][i]*(g+r)+i);
		}
	}
	printf("%lld\n",ans<1e17?ans:-1);
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define lowbit(x) (x&(-x))
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=2e5+5;
int n,m;
char s[5],c[5];

struct Edge
{
	int u,v;
	bool operator < (const Edge &x)const
	{
		if(u==x.u) return v<x.v;
		return u<x.u;
	}
};

map<Edge,int> mp;
multiset<Edge> A,B;

signed main()
{
	n=read();m=read();
	while(m--)
	{
		scanf("%s",s+1);
		if(s[1]=='+')
		{
			int u=read(),v=read();
			scanf("%s",c+1);
			Edge x=(Edge){min(u,v),max(u,v)};
			if(mp[(Edge){v,u}])
			{
				if(mp[(Edge){v,u}]==c[1]-'a'+1)
					B.insert(x);
				else A.insert(x);
			}
			mp[(Edge){u,v}]=c[1]-'a'+1;
		}
		if(s[1]=='-')
		{
			int u=read(),v=read();
			Edge x=(Edge){min(u,v),max(u,v)};
			if(A.count(x)) A.erase(A.find(x));
			if(B.count(x)) B.erase(B.find(x));
			mp[(Edge){u,v}]=0;
		}
		if(s[1]=='?')
		{
			int x=read();
			if(B.size()||(x%2==1&&A.size()))
				printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
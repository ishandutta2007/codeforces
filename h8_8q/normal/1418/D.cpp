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
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

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

const int N=1e5+5;
int n,q;

multiset<int> s,ans;

inline void query()
{
	if(s.size()<=1)
	{
		printf("0\n");
		return;
	}
	auto mn=s.begin();
	auto mx=s.end();mx--;
	auto len=ans.end();len--;
	printf("%lld\n",*mx-*mn-*len);
}

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
		s.insert(read());
	int last=-1;
	for(auto i=s.begin();i!=s.end();++i)
	{
		if(last!=-1)
			ans.insert(*i-last);
		last=*i;
	}
	query();
	while(q--)
	{
		int opt=read();
		if(opt==0)
		{
			int x=read();
			auto now=s.find(x);
			if(now==s.begin())
			{
				int n1=*now;++now;
				if(now!=s.end())
				{
					int n2=*now;
					ans.erase(ans.find(n2-n1));	
				}
			}
			else
			{
				int n1=*now;--now;
				int n2=*now;++now;++now;
				ans.erase(ans.find(n1-n2));
				if(now!=s.end())
				{
					int n3=*now;
					ans.erase(ans.find(n3-n1));
					ans.insert(n3-n2);
				}
			}
			s.erase(s.find(x));
		}
		else
		{
			auto now=s.insert(read());
			if(now==s.begin())
			{
				int n1=*now;++now;
				if(now!=s.end())
				{
					int n2=*now;
					ans.insert(n2-n1);
				}
			}
			else
			{
				int n1=*now;--now;
				int n2=*now;++now;++now;
				ans.insert(n1-n2);
				if(now!=s.end())
				{
					int n3=*now;
					ans.insert(n3-n1);
					ans.erase(ans.find(n3-n2));
				}
			}
		}
		query();
	}
	return 0;
}
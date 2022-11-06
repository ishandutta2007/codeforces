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
#define INF 0x3f3f3f3f3f3f3f3f

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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

int t,a,b;

vector<int> ans;

inline bool check(int x,int y,int p,int t)
{
	int sum=p-x;
	if(sum==0)
	{
		if(t%2==0)
			return 1;
		return 0;
	}
	if(sum<0)
	{
		sum=-sum;
		if(x<sum) return 0;
		if(t<sum) return 0;
		x-=sum;t-=sum;y+=sum;
		if(t%2==1) return 0;
		if(x<t/2||y<t/2) return 0;
		return 1;
	}
	else
	{
		if(y<sum) return 0;
		if(t<sum) return 0;
		y-=sum;t-=sum;x+=sum;
		if(t%2==1) return 0;
		if(x<t/2||y<t/2) return 0;
		return 1;
	}
}

signed main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();
		ans.clear();
		for(int i=0;i<=a+b;++i)
		{
			int flag=0;
			if(check((a+b+1)/2,(a+b)/2,a,i)) flag=1;
			if(check((a+b+1)/2,(a+b)/2,b,i)) flag=1;
			if(flag) ans.push_back(i);
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();++i)
			printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}
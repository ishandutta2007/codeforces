#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

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

const int N=1e6+5;
int t,n;
char s1[N],s2[N];

vector<pair<int,int> > op;

mt19937 rd(114514);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int fl=0;
		for(int i=1;i<=n;++i)
			if(s1[i]==s2[i]) fl++;
		if(fl%n!=0) puts("NO");
		else
		{
			op.clear();
			puts("YES");int now=s2[1]-'0';
			for(int i=1;i<=n;++i)
				if(s1[i]=='1')
				{
					op.push_back(mp(i,i));
					if(i!=1) now^=1;
				}
			if(now)
			{
				op.push_back(mp(1,1));
				op.push_back(mp(1,n));
				op.push_back(mp(2,n));
			}
			write(SZ(op));puts("");
			for(int i=0;i<SZ(op);++i)
				write(op[i].fi),putchar(' '),write(op[i].se),puts("");
		}
	}
	return 0;
}
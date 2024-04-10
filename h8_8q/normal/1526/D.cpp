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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=5e5+5;
int t,n,pos[30][N],b[30],c[30],num;
char s[N],ans[N],ANS[N];

struct BIT
{
	int c[N];
	inline int add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]+=v;
	}
	inline int s_query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	inline int query(int l,int r)
	{
		return s_query(r)-s_query(l-1);
	}
}sum;

inline int check();
void dfs(int u);

signed main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);num=-1;
		b[1]=1;b[2]=2;b[3]=3;b[4]=4;
		for(int i=1;i<=n;++i)
			c[s[i]-'A']++;
		do
		{
			int now=0;
			for(int i=1;i<=4;++i)
			{
				for(int j=1;j<=c['A'-'A']&&b[i]==1;++j) ans[++now]='A';
				for(int j=1;j<=c['N'-'A']&&b[i]==2;++j) ans[++now]='N';
				for(int j=1;j<=c['T'-'A']&&b[i]==3;++j) ans[++now]='T';
				for(int j=1;j<=c['O'-'A']&&b[i]==4;++j) ans[++now]='O';
			}
			int tmp=check();
			if(tmp>num)
			{
				num=tmp;
				cpy(ANS,ans,n+1);
			}
		}while(next_permutation(b+1,b+1+4));
		for(int i=1;i<=n;++i)
			putchar(ANS[i]);
		printf("\n");
		for(int i=1;i<=n;++i)
			ans[i]='\0';
		memset(c,0,sizeof(c));
	}
	return 0;
}

inline int check()
{
	int res=0;
	for(int i=1;i<=n;++i)
		sum.c[i]=0;
	int now[30];
	memset(now,0,sizeof(now));
	for(int i=1;i<=n;++i)
		pos[ans[i]-'A'][++now[ans[i]-'A']]=i;
	memset(now,0,sizeof(now));
	for(int i=1;i<=n;++i)
	{
		int tmp=pos[s[i]-'A'][++now[s[i]-'A']];
		res+=sum.query(tmp,n);sum.add(tmp,1);
	}
	return res;
}
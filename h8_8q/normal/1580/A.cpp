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

const int N=505;
int t,n,m,sm[N][N];
char s[N][N];

inline int query(int l1,int r1,int l2,int r2)
{
	return sm[l2][r2]-sm[l2][r1-1]-sm[l1-1][r2]+sm[l1-1][r1-1];
}

inline int query2(int l1,int r1,int l2,int r2)
{
	int res=query(l1+1,r1+1,l2-1,r2-1);
	res+=l2-l1-1-query(l1,r1+1,l1,r2-1);
	res+=l2-l1-1-query(l2,r1+1,l2,r2-1);
	res+=r2-r1-1-query(l1+1,r1,l2-1,r1);
	res+=r2-r1-1-query(l1+1,r2,l2-1,r2);
	return res;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				sm[i][j]=s[i][j]-'0'+sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1];
		int ans=INF;
		for(int i=1;i<=n;++i)
			for(int j=i+4;j<=n;++j)
			{
				vector<int> ok;
				for(int k=1;k<=m;++k)
					if(j-i-1-query(i+1,k,j-1,k)<=16)
						ok.push_back(k);
				for(int k1=0;k1<ok.size();++k1)
					for(int k2=k1+1;k2<ok.size();++k2)
						if(ok[k2]-ok[k1]+1>=4)
						{
							int tmp=query2(i,ok[k1],j,ok[k2]);
							if(tmp>16) break;
							ans=min(ans,tmp);
						}
			}
		printf("%lld\n",ans);
	}
	return 0;
}
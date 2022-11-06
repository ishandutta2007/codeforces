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

const int N=1005;
int n,ans[5];
char S[N],s[N];

inline int query()
{
	//int res=0;
	//for(int i=1;i<=n;++i)
	//	if(s[i]!=S[i])
	//		res++;
	//return res;
	printf("? %s\n",s+1);
	fflush(stdout);
	return read();
}

inline void merge(int l,int r,int las,int qwq,int id)
{
	if(l==r)
	{
		ans[id]=l;
		return;
	}
	if(las==-1)
	{
		s[1]=id+'0';
		for(int i=2;i<=n;++i)
			s[i]=(id^1)+'0';
		las=query();qwq=las-1;
	}
	int A=las,B,len=mid-l+1;
	for(int i=1;i<=n;++i)
		s[i]=id+'0';
	for(int i=mid+1;i<=r;++i)
		s[i]=(id^1)+'0';
	B=query();
	int a=(A-B+len)/2,b=qwq-a;
	if(a) merge(l,mid,B-b+r-mid-b-len+a+a,a,id);
	else merge(mid+1,r,B,b,id);
}

signed main()
{
	n=read();
	//scanf("%s",S+1);
	//n=strlen(S+1);
	for(int i=1;i<=n;++i)
		s[i]='0';
	int p1=query();
	s[1]='1';
	int p2=query();
	if((p1-p2+1)/2==1)
		ans[1]=1,merge(2,n,-1,-1,0);
	else ans[0]=1,merge(2,n,-1,-1,1);
	printf("! %lld %lld\n",ans[0],ans[1]);
	return 0;
}
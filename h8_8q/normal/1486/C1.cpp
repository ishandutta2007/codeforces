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

int n,l,r;

inline int qus(int l,int r);
void work(int l,int r,int fa);

signed main()
{
	n=read();
	work(1,n,qus(1,n));
	return 0;
}

inline int qus(int l,int r)
{
	printf("? %lld %lld\n",l,r);
	fflush(stdout);
	return read();
}

void work(int l,int r,int fa)
{
	if(l+1==r)
	{
		int x=qus(l,r);
		if(x==l) printf("! %lld\n",r);
		else printf("! %lld\n",l);
		fflush(stdout);
		return;
	}
	if(l+2==r)
	{
		int x=qus(l,r);
		if(x==l)
		{
			int y=qus(l+1,r);
			if(y==l+1) printf("! %lld\n",r);
			else printf("! %lld\n",l+1);
			fflush(stdout);
		}
		if(x==r)
		{
			int y=qus(l,r-1);
			if(y==l) printf("! %lld\n",r-1);
			else printf("! %lld\n",l);
			fflush(stdout);
		}
		if(x==l+1)
		{
			int y=qus(l,l+1);
			if(y==l+1) printf("! %lld\n",l);
			else printf("! %lld\n",r);
			fflush(stdout);
		}
		return;
	}
	int L=qus(l,mid);
	int R=qus(mid+1,r);
	if(fa==L) work(l,mid,L);
	else if(fa==R) work(mid+1,r,R);
	else if(fa<=mid) work(mid+1,r,R);
	else work(l,mid,L);
}
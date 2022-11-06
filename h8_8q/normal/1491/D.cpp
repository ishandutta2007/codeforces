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

const int N=105;
int t,x,y,a[N],b[N];

vector<int> p,q;

inline int querya(int l,int r);
inline int queryb(int l,int r);

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	while(t--)
	{
		x=read();y=read();
		if(x>y)
		{
			printf("No\n");
			continue;
		}
		p.clear();q.clear();
		a[0]=(x&1);
		if(a[0]) p.push_back(0);
		p.push_back(0);
		for(int i=1;i<=29;++i)
		{
			a[i]=a[i-1]+((x>>i)&1);
			if(((x>>i)&1)) p.push_back(i);
		}
		b[0]=(y&1);
		if(b[0]) q.push_back(0);
		q.push_back(0);
		for(int i=1;i<=29;++i)
		{
			b[i]=b[i-1]+((y>>i)&1);
			if(((y>>i)&1)) q.push_back(i);
		}
		int i=p.size()-1,j=q.size()-1,fl=1,tag=1;
		while(j>=1&&fl)
		{
			int sm=0;
			while(i>=1&&p[i]>q[j])
				i--;
			if(i==0) fl=0;
			if(tag&&p[i]==q[j])
			{
				if(querya(q[j-1]+1,q[j]-1)>0)
					fl=0;
			}
			else tag=0;
			j--;i--;
		}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

inline int querya(int l,int r)
{
	if(l>r) return 0;
	if(l==0) return a[r];
	return a[r]-a[l-1];
}

inline int queryb(int l,int r)
{
	if(l>r) return 0;
	if(l==0) return b[r];
	return b[r]-b[l-1];
}
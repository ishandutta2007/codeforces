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
int t,n,a[N],b[N],ans;
char s[N];

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		x+=n+1;
		for(;x<=n*2+1;x+=lowbit(x))
			c[x]+=v;
	}
	inline int query(int x)
	{
		x+=n+1;
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	inline int query(int l,int r)
	{
		if(l>r) return 0;
		return query(r)-query(l-1);
	}
	inline void clear()
	{
		for(int i=1;i<=n*2+1;++i)
			c[i]=0;
	}
}s1,s2,s3;

void solve(int l,int r)
{
	if(l==r)
	{
		ans++;
		return;
	}
	solve(l,mid);
	solve(mid+1,r);
	if(s[mid]=='(') a[mid]=0,b[mid]=1;
	else b[mid]=0,a[mid]=1;
	for(int i=mid-1;i>=l;--i)
		if(s[i]=='(')
		{
			if(a[i+1])
				a[i]=a[i+1]-1,b[i]=b[i+1];
			else a[i]=a[i+1],b[i]=b[i+1]+1;
		}
		else
		{
			a[i]=a[i+1]+1;
			b[i]=b[i+1];
		}
	if(s[mid+1]=='(') a[mid+1]=0,b[mid+1]=1;
	else b[mid+1]=0,a[mid+1]=1;
	for(int i=mid+2;i<=r;++i)
		if(s[i]==')')
		{
			if(b[i-1])
				b[i]=b[i-1]-1,a[i]=a[i-1];
			else a[i]=a[i-1]+1,b[i]=b[i-1];
		}
		else
		{
			a[i]=a[i-1];
			b[i]=b[i-1]+1;
		}
	vector<pair<int,int> > p1,p2;
	for(int i=l;i<=mid;++i)
		p1.push_back(mp(b[i],i));
	for(int i=mid+1;i<=r;++i)
		p2.push_back(mp(a[i],i));
	sort(p1.begin(),p1.end());
	sort(p2.begin(),p2.end());int j=-1;
	for(int i=0;i<SZ(p1);++i)
	{
		while(j+1<SZ(p2)&&p2[j+1].fi<p1[i].fi)
		{
			++j;
			s1.add(b[p2[j].se]-a[p2[j].se],1);
			s2.add(b[p2[j].se]-a[p2[j].se],b[p2[j].se]-a[p2[j].se]);
		}
		ans+=a[p1[i].se]*s1.query(-n,a[p1[i].se]-b[p1[i].se]);
		ans+=b[p1[i].se]*s1.query(a[p1[i].se]-b[p1[i].se]+1,n)+s2.query(a[p1[i].se]-b[p1[i].se]+1,n);
	}
	for(int i=0;i<=j;++i)
	{
		s1.add(b[p2[i].se]-a[p2[i].se],-1);
		s2.add(b[p2[i].se]-a[p2[i].se],-b[p2[i].se]+a[p2[i].se]);
	}
	j=SZ(p2);
	for(int i=SZ(p1)-1;i>=0;--i)
	{
		while(j-1>=0&&p2[j-1].fi>=p1[i].fi)
		{
			--j;
			s1.add(a[p2[j].se]-b[p2[j].se],1);
			s2.add(a[p2[j].se]-b[p2[j].se],a[p2[j].se]);
			s3.add(a[p2[j].se]-b[p2[j].se],b[p2[j].se]);
		}
		ans+=s3.query(-n,b[p1[i].se]-a[p1[i].se]);
		ans+=(a[p1[i].se]-b[p1[i].se])*s1.query(b[p1[i].se]-a[p1[i].se]+1,n)+s2.query(b[p1[i].se]-a[p1[i].se]+1,n);
	}
	for(int i=j;i<SZ(p2);++i)
	{
		s1.add(a[p2[i].se]-b[p2[i].se],-1);
		s2.add(a[p2[i].se]-b[p2[i].se],-a[p2[i].se]);
		s3.add(a[p2[i].se]-b[p2[i].se],-b[p2[i].se]);
	}
	return;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		ans=0;solve(1,n);
		write(ans);puts("");
	}
	return 0;
}
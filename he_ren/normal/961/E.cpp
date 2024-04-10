#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int n,sum[MAXN];
#define lowbit(x) ((x)&-(x))

inline void update(int x,int k)
{
	while(x<=n)
	{
		sum[x]+=k;
		x+=lowbit(x);
	}
}

inline int query(int x)
{
	int res=0;
	while(x)
	{
		res+=sum[x];
		x^=lowbit(x);
	}
	return res;
}

int a[MAXN];

struct Node
{
	int id,x;
}b[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.x<q.x;}

int main(void)
{	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		chk_min(a[i],n);
		b[i]=(Node){i,a[i]};
	}
	
	sort(b+1,b+n+1,cmp);
	ll ans=0;
	for(int i=1,j=1; i<=n; ++i)
	{
		update(a[i],1);
		while(b[j].x==i)
		{
			ans += i-query(b[j].id-1);
			++j;
		}
		if(a[i]>=i) --ans;
	}
	cout<<(ans>>1ll);
	return 0;
}
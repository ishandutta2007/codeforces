#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
const int MAXM = MAXN;
const ll linf = 1e16;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

struct BIT
{
	ll tree[MAXN],n;
	#define lowbit(x) ((x)&-(x))
	inline void init(int n_){ n=n_+1; memset(tree,0,sizeof(tree));}
	inline void update(int x,ll k)
	{
		++x; 
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline void update(int l,int r,ll k){ update(l,k); update(r+1,-k);}
	inline ll query(int x)
	{
		++x;
		ll res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
};

int a[MAXN],p[MAXN];
int b[MAXM];

BIT f;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	f.init(m);
	f.update(1,m,linf); 
	
	for(int i=1; i<=n; ++i)
	{
		int x = lower_bound(b+1,b+m+1,a[i])-b;
		
		if(p[i]<0) f.update(x,m,p[i]);
		if(a[i]==b[x])
		{
			ll lst = f.query(x);
			ll now = f.query(x-1);
			if(lst>now) f.update(x,x,now-lst);
		}
		f.update(0,x-1,p[i]);
	}
	
	ll ans = f.query(m);
	if(ans >= (linf>>1)) printf("NO");
	else printf("YES\n%lld",ans);
	return 0;
}
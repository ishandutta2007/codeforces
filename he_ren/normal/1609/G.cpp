#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline ll read(void)
{
	ll res = 0;
	char c = getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

struct BIT
{
	ll tree[MAXM];
	int n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,ll k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline ll query(int x)
	{
		ll res = 0;
		while(x)
			res += tree[x], x ^= lowbit(x);
		return res;
	}
	inline int getlst(ll k)
	{
		int res = 0;
		for(int i=1<<18; i>=1; i>>=1)
			if(res+i <= n && tree[res+i] <= k)
				res += i, k -= tree[res];
		return res;
	}
}tree, bsum1, bsum2;

int n,m;
ll a[MAXN], b[MAXM], difb[MAXM];

inline ll getB(int x)
{
	return b[x] + bsum1.query(x) * x - bsum2.query(x);
}

int main(void)
{
	int Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1; i<=n; ++i) a[i] = read();
	for(int i=1; i<=m; ++i) b[i] = read();
	
	ll sum = 0;
	for(int i=1; i<=n; ++i) sum += a[i];
	for(int i=1; i<=m; ++i) sum += b[i];
	
	tree.n = m - 1;
	bsum1.n = bsum2.n = m;
	
	for(int i=1; i<m; ++i) difb[i] = b[i+1] - b[i];
	for(int i=1; i<m; ++i) tree.update(i, difb[i] - difb[i-1]);
	
	while(Q--)
	{
		{
			int type, k, d;
			scanf("%d%d%d",&type,&k,&d);
			sum += (ll)k * (k + 1) / 2 * d;
			if(type == 1)
			{
				for(int i=1; i<=k; ++i)
					a[n-k+i] += d * i;
			}
			else
			{
				tree.update(max(m-k, 1), d);
				
				bsum1.update(m-k+1, d);
				bsum2.update(m-k+1, (ll)d * (m-k));
			}
		}
		
		ll ans = sum;
		
//		printf("a = ");for(int i=1; i<=n; ++i) printf("%lld ",a[i]); printf("\n");
//		printf("b = ");for(int i=1; i<=m; ++i) printf("%lld ",getB(i)); printf("\n");
		
		int pos = 1;
		for(int i=1; i<n; ++i)
		{
			int nxt = tree.getlst(a[i+1] - a[i]) + 1;
			ans += a[i] * (nxt - pos);
			ans += getB(nxt);
			pos = nxt;
//			printf("i = %d, pos = %d\n",i,pos);
		}
		ans += a[n] * (m - pos);
		
		printf("%lld\n",ans);
	}
	return 0;
}
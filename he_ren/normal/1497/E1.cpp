#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXD = 20 + 2;
const int MAXA = 1e7 + 5;

struct BIT
{
	int tree[MAXN],n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(void){ memset(tree,0,(n+1)<<2);}
	inline void update(int x,int k)
	{
		x = n - x + 1;
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		x = n - x + 1;
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int get_fir(int x)
	{
		int res = 0;
		for(int i=18; i>=0; --i)
			if(res + (1<<i) <= n && tree[res + (1<<i)] <= x)
				res += 1<<i, x -= tree[res];
		return n - res + 1;
	}
};

bool isnp[MAXA];
int pri[MAXA], pcnt = 0, f[MAXA];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1; f[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i, f[i] = i;
		for(int j=1; j<=pcnt && (ll)pri[j] * i <= n; ++j)
		{
			int x = i * pri[j];
			isnp[x] = 1;
			f[x] = f[i] % pri[j]? f[i] * pri[j]: f[i] / pri[j];
			if(!(i%pri[j])) break;
		}
	}
}

int a[MAXN];
int dp[MAXN][MAXD];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]), a[i] = f[a[i]];
	
	static int dsc[MAXN];
	int dcnt = 0;
	for(int i=1; i<=n; ++i) dsc[++dcnt] = a[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i) a[i] = lower_bound(dsc+1,dsc+dcnt+1,a[i]) - dsc;
	
	static BIT tree;
	static int lst[MAXN];
	memset(lst,0,(n+1)<<2);
	tree.n = n;
	tree.clear();
	
	for(int i=1; i<=n; ++i)
	{
		if(lst[a[i]]) tree.update(lst[a[i]], 1);
		lst[a[i]] = i;
		memset(dp[i],0x3f,sizeof(dp[i]));
		for(int j=0; j<=d; ++j)
		{
			int pos = tree.get_fir(j);
			for(int k=0; j+k<=d; ++k)
				dp[i][j+k] = min(dp[i][j+k], dp[pos-1][k] + 1);
		}
	}
	printf("%d\n",dp[n][d]);
}

int main(void)
{
	sieve(MAXA-1);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
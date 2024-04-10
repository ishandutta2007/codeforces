#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5000 + 5;
const int MAXD = 8 + 3;
const int ALL = (1<<8) + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k, x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x], x ^= lowbit(x);
		return res;
	}
}tree;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int p[MAXN], ip[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d",&p[i]);
	
	for(int i=1; i<=n; ++i)
		ip[p[i]] = i;
	
	static int val[MAXN][MAXD];
	
	tree.n = n;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<=d && i+j<=n; ++j)
			val[i+j][j] = (i-1) - tree.query(ip[i+j]);
		tree.update(ip[i], 1);
	}
	
	int all = (1<<d)-1;
	
	vector< vector<int> > dp(d+1, vector<int>(all+1, inf));
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i)
	{
		vector< vector<int> > ndp(d+1, vector<int>(all+1, inf));
		for(int j=0; j<=d; ++j)
			for(int mask=0; mask<=all; ++mask) if(dp[j][mask] != inf)
			{
				auto getcost = [&] (int x)
				{
					int res = val[x][x-(i-j)];
					for(int k=1; k<=d; ++k)
						if(bdig(mask, k-1) && ip[(i-j)+k] > ip[x])
							++res;
					return res;
				};
				
				{
					int jj = j, nxt = mask;
					while(nxt & 1) --jj, nxt >>= 1;
					--jj, nxt >>= 1;
					chk_min(ndp[jj+1][nxt], dp[j][mask] + getcost(i-j));
				}
				
				if(j+1 <= d)
				{
					for(int k=1; k<=d; ++k) if(!bdig(mask, k-1))
					{
						if(i-j+k > n) continue;
						chk_min(ndp[j+1][mask | bbit(k-1)], dp[j][mask] + getcost(i-j+k));
					}
				}
			}
		dp.swap(ndp);
	}
	
	int ans = dp[0][0];
	printf("%d",ans);
	return 0;
}
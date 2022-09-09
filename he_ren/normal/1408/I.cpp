#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = (1<<16) + 5;
const int MAXD = 16 + 5;
const int MAXC = 16 + 5;
const int ALL = 32 + 5;
const int mod = 998244353;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

ll fac[MAXN], inv[MAXN];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}
ll c_small[MAXD][MAXD];

int n,d,cc, high = 0, all;
int a[MAXN];

int dp[2][2][ALL][MAXD];
void get_dp(vector<int> &vec)
{
	memset(dp[0], 0, sizeof(dp[0]));
	dp[0][0][0][0] = 1;
	
	for(register int i=1; i<=(int)vec.size(); ++i)
	{
		register int now = (i&1), lst = now^1;
		
		register int x = vec[i-1];
		
		for(register int j=0; j<=all; ++j)
			for(register int k=0; k<=d; ++k)
			{
				ll dp0 = 0, dp1 = 0;
				
				for(register int use=0; use<=k && use<=x; ++use)
				{
					dp0 += dp[lst][0][j ^ (x-use)][k-use] * c_small[k][use] %mod;
					dp1 += dp[lst][1][j ^ (x-use)][k-use] * c_small[k][use] %mod;
				}
				for(register int use=x+1; use<=k; ++use)
				{
					dp0 += dp[lst][1][j ^ (all-(use-x)+1)][k-use] * c_small[k][use] %mod;
					dp1 += dp[lst][0][j ^ (all-(use-x)+1)][k-use] * c_small[k][use] %mod;
				}
				
				dp[now][0][j][k] = dp0 %mod;
				dp[now][1][j][k] = dp1 %mod;
			}
	}
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	for(int i=0; i<MAXD; ++i)
	{
		c_small[i][0] = c_small[i][i] = 1;
		for(int j=1; j<i; ++j)
			c_small[i][j] = (c_small[i-1][j-1] + c_small[i-1][j]) %mod;
	}
	
	scanf("%d%d%d",&n,&d,&cc);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int allc = (1<<cc) - 1;
	
	while((1<<high) < d) ++high;
	all = (1<<high) - 1;
	
	static vector<int> g[MAXC];
	
	int already = 0;
	for(int i=1; i<=n; ++i)
	{
		int val = a[i] & all;
		if(val >= d)
		{
			already ^= a[i] ^ val;
			g[0].push_back(val);
//			printf("push to 0: a[%d]: %d\n",i,val);
			continue;
		}
		
		for(int j=high; j<cc; ++j)
			if(bdig(a[i],j))
			{
				already ^= a[i] ^ val;
				g[j - (high-1)].push_back(val);
//				printf("push to %d: a[%d]: %d\n",j - (high-1),i,val);
				break;
			}
	}
	
	static int f[MAXC][MAXD][MAXN], ff[MAXC][MAXD][MAXN];
	
	f[0][0][0] = 1;
	
	int m = cc-1 - (high-1);
	for(register int k=0; k<=m; ++k)
	{
		vector<int> &vec = g[k];
		get_dp(vec);
		
		register int now = (int)vec.size() & 1;
		register int cur_all = (1<<(k + high)) - 1;
		
//		for(int had=0; had<=1; ++had)
//			for(int i=0; i<=all; ++i)
//				for(int j=0; j<=d; ++j)
//					if(dp[now][had][i][j])
//						printf("%d: %d %d %d:  %d\n",k,had,i,j,dp[now][had][i][j]);
//		
//		printf("k: %d  more: %d\n",k,cur_all^all);
		
		for(register int res=0; res<=all; ++res)
			for(register int use=0; use<=d; ++use)
			{
				if(dp[now][0][res][use])
				{
					for(register int i=use; i<=d; ++i)
					{
						ll mul = dp[now][0][res][use] * c_small[i][use] %mod;
						
						for(register int j=0; j<=cur_all; ++j)	
							f[k+1][i][j] = (f[k+1][i][j] + f[k][i-use][j^res] * mul) %mod;
					}
				}
				
				if(dp[now][1][res][use])
				{
					for(register int i=use; i<=d; ++i)
					{
						ll mul = dp[now][1][res][use] * c_small[i][use] %mod;
						
						for(register int j=0; j<=cur_all; ++j)	
							ff[k+1][i][j] = (ff[k+1][i][j] + f[k][i-use][j^res] * mul) %mod;
					}
				}
			}
		
		for(int i=0; i<=d; ++i)
			for(int j=0; j<=cur_all; ++j)
				add_mod(f[k+1][i][j^cur_all^all], ff[k+1][i][j]);
	}
	
	static int ans[MAXN];
	
	ll possi = pw(pw(n,d), mod-2);
	for(int i=0; i<=allc; ++i)
		ans[i] = f[m+1][d][i ^ already] * possi %mod;
	
	for(int i=0; i<=allc; ++i)
		printf("%d ",ans[i]);
	return 0;
}
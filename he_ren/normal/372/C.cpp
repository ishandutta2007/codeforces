#include<cstdio>
typedef long long ll;
const int MAXN = 150000 + 5;
const int MAXM = 300 + 5;
const ll inf = 0x3fffffffffffffff;

inline ll abs(ll x){ return x<0? -x: x;}
inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

int a[MAXM],b[MAXM],t[MAXM];
ll dp[3][MAXN];

int q[MAXN],hd=0,tl=0;
inline void init(void){ hd=tl=0;}
inline void push(int i,int x)
{
	while(tl>hd && dp[i][q[tl]]>dp[i][x]) --tl;
	q[++tl]=x;
}
inline void pop(void)
{
	if(hd < tl) ++hd;
}

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i) scanf("%d%d%d",&a[i],&b[i],&t[i]);
	
	for(int i=1; i<=m; ++i)
	{
		int now = i&1, last = now^1;
		
		ll nd = (ll)d*(t[i]-t[i-1]);
		
		init();
		for(int j=1; j<=nd && j<=n; ++j)
			push(last,j);
		
		for(int j=1; j<=n; ++j)
		{
			if(q[hd+1] < j-nd) pop();
			if(j+nd <= n) push(last,j+nd);
			dp[now][j] = dp[last][q[hd+1]] + abs((ll)a[i]-j);
		}
	}
	
	ll ans=inf;
	for(int i=1; i<=n; ++i)
		chk_min(ans, dp[m&1][i]);
	ll sum=0;
	for(int i=1; i<=m; ++i) sum+=b[i];
	printf("%lld",sum-ans);
	return 0;
}
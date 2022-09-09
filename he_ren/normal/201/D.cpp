#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 15 + 5;
const int MAXM = 5e5 + 5;
const int ALL = (1<<15) + 5;
const int MAXD = MAXN * MAXN;
const int inf = 0x3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int num1[ALL];

int n;
string a[MAXN], b[MAXM];
map<string,int> ina;

int solve(void)
{
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) cin >> b[i];
	
	static int nxt[MAXM][MAXN];
	for(int i=1; i<=n; ++i) nxt[m+1][i] = m+1;
	for(int i=m; i>=1; --i)
	{
		for(int j=1; j<=n; ++j) nxt[i][j] = nxt[i+1][j];
		if(ina.find(b[i]) != ina.end())
			nxt[i][ina[b[i]]] = i;
	}
	
	static int dp[ALL][MAXD];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	
	int all = (1<<n) - 1, d = n * (n-1) / 2;
	for(int mask=0; mask<all; ++mask)
		for(int x=0; x<=d; ++x) if(dp[mask][x] < m)
		{
			int cur = dp[mask][x] + 1;
			for(int i=1; i<=n; ++i) if(!bdig(mask, i-1) && nxt[cur][i] <= m)
				chk_min(dp[mask | bbit(i-1)][x + num1[mask & (all << i)]], nxt[cur][i]);
		}
	
	for(int i=0; i<=d; ++i)
		if(dp[all][i] <= m) return i;
	return inf;
}

int main(void)
{
	for(int i=1; i<ALL; ++i) num1[i] = num1[i ^ lowbit(i)] + 1;
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		cin >> a[i], ina[a[i]] = i;
	
	int Q;
	scanf("%d",&Q);
	int mnans=inf, mnpos=-1;
	for(int i=1; i<=Q; ++i)
	{
		int res = solve();
		if(res < mnans) mnans = res, mnpos = i;
	}
	
	if(mnans == inf) return printf("Brand new problem!"), 0;
	mnans = n * (n-1) / 2 - mnans + 1;
	
	printf("%d\n",mnpos);
	printf("[:");
	for(int i=1; i<=mnans; ++i) putchar('|');
	printf(":]");
	return 0;
}
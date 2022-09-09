#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXM = 18 + 3;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int a[MAXN], b[MAXM];

int hasa[MAXN], hasb[MAXN];
int lefb[MAXN], rigb[MAXN];

int pre[MAXN][MAXM], suf[MAXN][MAXM];

int main(void)
{
	int d,n,m;
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i)
		scanf("%d",&b[i]);
	
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	
	for(int i=1; i<=n; ++i)
		hasa[a[i]] = i;
	for(int i=1; i<=m; ++i)
		hasb[b[i]] = i;
	
	for(int i=1; i<=d; ++i)
		lefb[i] = hasb[i]? hasb[i]: lefb[i-1];
	for(int i=d; i>=1; --i)
		rigb[i] = hasb[i]? hasb[i]: rigb[i+1];
	
	for(int i=1; i<=m; ++i)
		pre[0][i] = mod - 1;
	for(int i=0; i<d; ++i)
		for(int j=1; j<=m; ++j)
		{
			add_mod(pre[i+1][j], (ll)pre[i][j] * (hasa[i+1]? abs(i+1-b[j]): 1) %mod);
			
			if(b[j] <= i)
			{
				int l = max(i+1, 2 * i - b[j]);
				int r = min(d, 2 * (i+1) - b[j] - 1);
				if(l <= r && rigb[l] && b[rigb[l]] <= r)
				{
					for(int k=rigb[l]; k<=m && b[k] <= r; ++k)
					{
						add_mod(pre[i+1][k], (mod - (ll)pre[i][j]) * (hasa[i+1]? abs(i+1-b[k]): 1) %mod);
					}
				}
			}
		}
	
	for(int i=1; i<=m; ++i)
		suf[d][i] = 1;
	for(int i=d-1; i>=0; --i)
		for(int j=1; j<=m; ++j)
		{
			add_mod(suf[i][j], (ll)suf[i+1][j] * (hasa[i+1]? abs(i+1-b[j]): 1) %mod);
			
			if(b[j] <= i)
			{
				int l = max(i+1, 2 * i - b[j]);
				int r = min(d, 2 * (i+1) - b[j] - 1);
				if(l <= r && rigb[l] && b[rigb[l]] <= r)
				{
					for(int k=rigb[l]; k<=m && b[k] <= r; ++k)
					{
						add_mod(suf[i][j], (mod - (ll)suf[i+1][k]) * (hasa[i+1]? abs(i+1-b[k]): 1) %mod);
					}
				}
			}
		}
	
	ll more = 1;
	for(int i=1; i<=n+1; ++i)
		more = more * (d+1) %mod;
	
	static int res[MAXN];
	for(int i=1; i<=d; ++i) if(!hasa[i])
	{
		for(int j=1; j<=m; ++j)
			add_mod(res[i], (ll)pre[i][j] * suf[i][j] %mod * abs(b[j] - i) %mod);
		add_mod(res[i], more);
	}
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",res[x]);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e4 + 5;
const int MAXQ = 2e4 + 5;
const int d = 30;
const int lb = 14;
const int inf = 0x3f3f3f3f;

int a[MAXN];

int f[MAXN][lb+1][d+1], g[MAXN][lb+1][d+1];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		a[i] = min(n, a[i] + i);
	
	static int sta[MAXN], tp = 0;
	for(int i=n; i>=1; --i)
	{
		while(tp && a[sta[tp]] <= a[i]) --tp;
		sta[++tp] = i;
		
		for(int j=0; j<=lb; ++j)
			for(int k=0; k<=d; ++k)
			{
				if(j == 0)
				{
					f[i][j][k] = *lower_bound(sta+1, sta+tp+1, min(a[i]+k, n), greater<int>());
					g[i][j][k] = min(a[i]+k, n);
				}
				else
				{
					int cur = i;
					for(int kk=0; kk<=k; ++kk)
					{
						int t = f[ f[i][j-1][kk] ][j-1][k-kk];
						if(a[t] > a[cur]) cur = t;
					}
					f[i][j][k] = cur;
					
					cur = i;
					for(int kk=0; kk<=k; ++kk)
						cur = max(cur, g[ f[i][j-1][kk] ][j-1][k-kk]);
					g[i][j][k] = cur;
				}
			}
	}
	
	while(Q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(l == r)
		{
			printf("0\n");
			continue;
		}
		
		int res = 0;
		array<int,d+1> pos, npos;
		pos.fill(l);
		for(int i=lb; i>=0; --i)
		{
			bool ok = 1;
			for(int j=0; j<=k; ++j)
				if(g[pos[j]][i][k-j] >= r)
				{
					ok = 0;
					break;
				}
			if(!ok) continue;
			
			for(int j=0; j<=k; ++j)
			{
				int cur = l;
				for(int jj=0; jj<=j && cur<r; ++jj)
				{
					int t = f[pos[jj]][i][j-jj];
					if(a[t] > a[cur]) cur = t;
				}
				npos[j] = cur;
			}
			res |= 1 << i;
			pos.swap(npos);
		}
		
		++res;
		printf("%d\n",res);
	}
	return 0;
}
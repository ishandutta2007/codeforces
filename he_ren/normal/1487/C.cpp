#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int res[MAXN][MAXN];
inline void adde(int u,int v,int w){ res[u][v] = w; res[v][u] = -w;}

void get_res1(int n)
{
	if(n == 1) return;
	get_res1(n-2);
	
	int nn = n / 2;
	for(int i=1; i<=nn; ++i)
		adde(n, i, 1), adde(n-1, i, -1);
	for(int i=nn+1; i<=n-2; ++i)
		adde(n-1, i, 1), adde(n, i, -1);
	adde(n-1, n, 1);
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	if(n&1) get_res1(n);
	else
	{
		for(int i=1; i<=n; i+=2) adde(i, i+1, 0);
		for(int i=1; i<=n; i+=2)
			for(int j=i+2; j<=n; j+=2)
			{
				adde(i, j, 1); adde(i, j+1, -1);
				adde(i+1, j, -1); adde(i+1, j+1, 1);
			}
	}
	
//	int x = 0;
//	for(int i=2; i<=n; ++i)
//	{
//		if(res[1][i] == 0) ++x;
//		if(res[1][i] == 1) x += 3;
//	}
//	
//	for(int i=1; i<=n; ++i)
//	{
//		int y = 0;
//		for(int j=1; j<=n; ++j) if(j != i)
//		{
//			if(res[i][j] == 0) ++y;
//			if(res[i][j] == 1) y += 3;
//		}
//		if(y != x) printf("error! %d %d\n",x,y);
//	}
	
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j) printf("%d ",res[i][j]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
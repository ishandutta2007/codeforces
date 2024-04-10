#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 100 + 5;

int f[MAXN][MAXN][2][2];

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int c[2] = {0,0};
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		x &= 1;
		++c[x];
	}
	
	if(f[c[0]][c[1]][0][0])
		printf("Alice\n");
	else
		printf("Bob\n");
}

int main(void)
{
	f[0][0][0][0] = f[0][0][1][0] = 1;
	for(int i=0; i<MAXN; ++i)
		for(int j=0; j<MAXN; ++j)
			for(int k=0; k<=1; ++k)
				for(int has=0; has<=1; ++has)
				{
					if(i == 0 && j == 0) continue;
					
					if(k == 0)
					{
						if(i) f[i][j][k][has] |= f[i-1][j][k^1][has];
						if(j) f[i][j][k][has] |= f[i][j-1][k^1][has^1];
					}
					else
					{
						f[i][j][k][has] = 1;
						if(i) f[i][j][k][has] &= f[i-1][j][k^1][has];
						if(j) f[i][j][k][has] &= f[i][j-1][k^1][has];
					}
				}
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
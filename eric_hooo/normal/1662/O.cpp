#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

bool canl[400][30], canr[400][30], canu[400][30], cand[400][30];
int f[400][30];

bool valid = 1;
void dfs(int x,int y,int k)
{
	if(!valid) return;
	if(x<0) x += 360;
	if(x>=360) x -= 360;
	
	if(f[x][y] == inf) f[x][y] = k;
	else
	{
		if(f[x][y] != k){ valid = 0; return;}
		return;
	}
	
	if(canu[x][y]) dfs(x, y+1, k);
	if(cand[x][y]) dfs(x, y-1, k);
	if(canl[x][y]) dfs(x-1, y, k-1);
	if(canr[x][y]) dfs(x+1, y, k+1);
}

void solve(void)
{
	memset(canl, 0, sizeof(canl));
	memset(canr, 0, sizeof(canr));
	memset(canu, 0, sizeof(canu));
	memset(cand, 0, sizeof(cand));
	memset(f, 0x3f, sizeof(f));
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		static char op[10];
		scanf("%s",op+1);
		if(op[1] == 'C')
		{
			int y, xl, xr;
			scanf("%d%d%d",&y,&xl,&xr);
			if(xl <= xr)
			{
				for(int x=xl; x+1<=xr; ++x)
					canr[x][y] = canl[x+1][y] = 1;
			}
			else
			{
				for(int x=xl; x+1<360; ++x)
					canr[x][y] = canl[x+1][y] = 1;
				for(int x=0; x+1<=xr; ++x)
					canr[x][y] = canl[x+1][y] = 1;
				canr[359][y] = canl[0][y] = 1;
			}
		}
		else
		{
			int yl, yr, x;
			scanf("%d%d%d",&yl,&yr,&x);
			for(int y=yl; y+1<=yr; ++y)
				canu[x][y] = cand[x][y+1] = 1;
		}
	}
	
	valid = 1;
	for(int x=0; x<360; ++x)
		for(int y=1; y<=20; ++y)
			if(f[x][y] == inf) dfs(x, y, 0);
	if(valid)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
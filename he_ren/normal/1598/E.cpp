#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;

int n,m;
int f[MAXN][MAXM][2];
bool fob[MAXN][MAXM];

ll ans = 0;
void upd_f(int x,int y)
{
	if(x < 1 || x > n || y < 1 || y > m) return;
	ans -= max(f[x][y][0] + f[x][y][1] - 1, 0);
	if(!fob[x][y])
	{
		f[x][y][0] = f[x+1][y][1] + 1;
		f[x][y][1] = f[x][y+1][0] + 1;
	}
	else
	{
		f[x][y][0] = f[x][y][1] = 0;
	}
	ans += max(f[x][y][0] + f[x][y][1] - 1, 0);
}

int main(void)
{
	int Q;
	scanf("%d%d%d",&n,&m,&Q);
	
	for(int i=n; i>=1; --i)
		for(int j=m; j>=1; --j)
			upd_f(i,j);
	
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		fob[x][y] ^= 1;
		while(x >= 1 && y >= 1)
		{
			upd_f(x, y);
			upd_f(x - 1, y);
			upd_f(x, y - 1);
			--x; --y;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
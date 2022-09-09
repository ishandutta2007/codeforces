#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 150 + 5;
const int MAXD = 50 + 5;
const int mod = 51123987;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

char s[MAXN];
int f[MAXN][MAXD][MAXD][MAXD], res[MAXD][MAXD][MAXD];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	static int nxt[MAXN][5];
	nxt[n+1][0] = nxt[n+1][1] = nxt[n+1][2] = n+1;
	for(int i=n; i>=0; --i)
	{
		for(int j=0; j<3; ++j) nxt[i][j] = nxt[i+1][j];
		if(i) nxt[i][s[i] - 'a'] = i;
	}
	
	int d = (n + 2) / 3;
	f[0][0][0][0] = 1;
	for(int i=0; i<=n; ++i)
		for(int x=0; x<=d; ++x)
			for(int y=0; y<=d; ++y)
				for(int z=0; z<=d; ++z) if(f[i][x][y][z])
				{
					int cur = f[i][x][y][z];
					add_mod(res[x][y][z], cur);
					add_mod(f[nxt[i][0]][x+1][y][z], cur);
					add_mod(f[nxt[i][1]][x][y+1][z], cur);
					add_mod(f[nxt[i][2]][x][y][z+1], cur);
				}
	
	int ans = 0;
	for(int x=0; x<=d; ++x)
		for(int y=max(0,x-1); y<=x+1; ++y)
		{
			int z = n - x - y;
			if(z<0 || abs(x-z) > 1 || abs(y-z) > 1) continue;
			add_mod(ans, res[x][y][z]);
		}
	
	printf("%d",ans);
	return 0;
}
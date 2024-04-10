#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e2 + 5;

char s[MAXN][MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	static int cnt[2][3];
	memset(cnt,0,sizeof(cnt));
	
	int tot = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) if(s[i][j] != '.')
			++cnt[s[i][j] == 'X'][(i+j)%3], ++tot;
	
	for(int x=0; x<3; ++x)
		for(int y=0; y<3; ++y) if(x != y)
			if(cnt[0][x] + cnt[1][y] <= tot/3)
			{
				for(int i=1; i<=n; ++i)
					for(int j=1; j<=n; ++j) if(s[i][j] != '.')
					{
						if(s[i][j] == 'O' && (i+j)%3 == x) s[i][j] = 'X';
						if(s[i][j] == 'X' && (i+j)%3 == y) s[i][j] = 'O';
					}
				
				for(int i=1; i<=n; ++i)
					printf("%s\n",s[i]+1);
				return;
			}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
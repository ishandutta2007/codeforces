#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e6 + 5;
const int d = 10;
const int MAXD = d + 5;
const int inf = 0x3f3f3f3f;

int cnt[MAXD][MAXD];

int solve(int x,int y)
{
	static int f[MAXD][MAXD];
	
	int res = 0;
	for(int i=0; i<d; ++i)
		for(int j=0; j<d; ++j) if(cnt[i][j])
		{
			f[i][j] = inf;
			for(int a=0; a<=d; ++a)
				for(int b=0; b<=d; ++b) if(a||b)
				{
					if((i + a*x + b*y) % 10 == j)
						f[i][j] = min(f[i][j], a+b - 1);
				}
			
			if(f[i][j] == inf) return -1;
			res += f[i][j] * cnt[i][j];
		}
	return res;
}

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=2; i<=n; ++i)
		++cnt[s[i-1]-'0'][s[i]-'0'];
	
	for(int x=0; x<d; ++x, putchar('\n'))
		for(int y=0; y<d; ++y)
			printf("%d ",solve(x,y));
	return 0;
}
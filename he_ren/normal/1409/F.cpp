#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN], t[10];

int main(void)
{
	int n,d;
	scanf("%d%d%s%s",&n,&d,s+1,t+1);
	
	if(t[1] == t[2])
	{
		for(int i=1; i<=n && d; ++i)
			if(s[i] != t[1])
				s[i] = t[1],
				--d;
		int cnt = 0;
		for(int i=1; i<=n; ++i)
			if(s[i] == t[1]) ++cnt;
		printf("%d",cnt * (cnt-1) / 2);
		return 0;
	}
	
	static int f[MAXN][MAXN][MAXN];
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=d; ++j)
			for(int k=0; k<=n; ++k)
				f[i][j][k] = -inf;
	f[0][0][0] = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<=d; ++j)
			for(int k=0; k<=i; ++k)
			{
				int now = f[i][j][k];
				
				chk_max(f[i+1][j][k], now);
				
				if(s[i+1] == t[1]) chk_max(f[i+1][j][k+1], now);
				if(j<d) chk_max(f[i+1][j+1][k+1], now);
				
				if(s[i+1] == t[2]) chk_max(f[i+1][j][k], now + k);
				if(j<d) chk_max(f[i+1][j+1][k], now + k);
			}
	
	int ans = 0;
	for(int i=0; i<=d; ++i)
		for(int j=0; j<=n; ++j)
			ans = max(ans, f[n][i][j]);
	printf("%d",ans);
	return 0;
}
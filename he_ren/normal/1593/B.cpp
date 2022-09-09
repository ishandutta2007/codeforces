#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXL = 30 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

char s[MAXL];
int f[MAXL][26][2];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	memset(f, 0x3f, sizeof(f));
	f[0][0][0] = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<25; ++j)
			for(int k=0; k<=1; ++k) if(f[i][j][k] != inf)
			{
				int x = s[i+1] - '0';
				chk_min(f[i+1][(j * 10 + x) % 25][k || x], f[i][j][k]);
				chk_min(f[i+1][j][k], f[i][j][k] + 1);
			}
	printf("%d\n",f[n][0][1]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
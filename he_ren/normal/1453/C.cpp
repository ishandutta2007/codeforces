#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int n;
char s[MAXN][MAXN];
int res[15];

inline void get_res(void)
{
	static int fr[15], lr[15], fc[MAXN][15], lc[MAXN][15];
	for(int k=0; k<=9; ++k) fr[k] = n+1, lr[k] = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int k=0; k<=9; ++k)
			fc[i][k] = n+1, lc[i][k] = 0;
		for(int j=1; j<=n; ++j)
			chk_min(fc[i][s[i][j] - '0'], j),
			chk_max(lc[i][s[i][j] - '0'], j);
		
		for(int k=0; k<=9; ++k)
			if(fc[i][k] <= lc[i][k])
				chk_min(fr[k], i), chk_max(lr[k], i);
	}
	
	for(int i=1; i<=n; ++i)
		for(int k=0; k<=9; ++k) if(fr[k] <= lr[k] && fc[i][k] <= lc[i][k])
		{
			int l = fc[i][k], r = lc[i][k];
			int u = fr[k], d = lr[k];
			
			chk_max(res[k], (r - l) * max(i-1, n-i));
			chk_max(res[k], max(n-l, r-1) * max(i-u, d-i));
		}
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int k=0; k<=9; ++k) res[k] = 0;
	get_res();
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j) swap(s[i][j], s[j][i]);
	get_res();
	
	for(int k=0; k<=9; ++k)
		printf("%d ",res[k]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
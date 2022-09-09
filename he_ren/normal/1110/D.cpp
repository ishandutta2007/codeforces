#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN], t[MAXM];
int f[MAXM][4][4];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) ++t[a[i]];
	for(int i=1; i<=m; ++i)
		for(int x=0; x<=2; ++x)
			for(int y=0; y<=2 && x + y <= t[i]; ++y)
				for(int z=0; z<=2 && x + y + z <= t[i] && y + z <= t[i+1] && z <= t[i+2]; ++z)
					chk_max(f[i+1][y][z], f[i][x][y] + (t[i] - x - y - z) / 3 + z);
	
	printf("%d",f[m+1][0][0]);
	return 0;
}
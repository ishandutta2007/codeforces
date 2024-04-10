#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

char s[MAXN][MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	if(m&1)
	{
		printf("YES\n");
		for(int i=1; i<=m+1; ++i)
			printf("%d ",(i&1)+1);
		return;
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			if(s[i][j] == s[j][i])
			{
				printf("YES\n");
				for(int k=1; k<=m+1; ++k)
					printf("%d ",k&1? i: j);
				return;
			}
	if(n == 2){ printf("NO\n"); return;}
	
	int p[10] = {0,1,2,3};
	do
	{
		int x = p[1], y = p[2], z = p[3];
		if(s[x][y] == s[y][z])
		{
			vector<int> ans;
			int len = m>>1;
			for(int i=1; i<=len+1; ++i) ans.push_back(i&1? y: x);
			reverse(ans.begin(), ans.end());
			for(int i=1; i<=len; ++i) ans.push_back(i&1? z: y);
			
			printf("YES\n");
			for(int i=0; i<=m; ++i) printf("%d ",ans[i]);
			return;
		}
	}while(next_permutation(p+1,p+3+1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
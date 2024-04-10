#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXM = 2e2 + 5;

int n,m;
int a[MAXN][MAXM];

int rs[MAXN], cs[MAXM];

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	for(int k: {1, n})
	{
		static int b[MAXN][MAXM];
		for(int j=1; j<=m; ++j) cs[j] = a[k][j];
		
		int chs = 0;
		for(int i=1; i<=n; ++i)
		{
			int cnt = 0;
			for(int j=1; j<=m; ++j)
			{
				b[i][j] = a[i][j] ^ cs[j];
				if(j > 1 && b[i][j] != b[i][j-1]) ++cnt;
			}
			if(cnt > 1) chs = -1;
			else if(cnt == 1)
			{
				if(chs) chs = -1;
				else chs = i;
			}
		}
		if(chs == -1) continue;
		
		for(int i=1; i<=chs; ++i) rs[i] = b[i][1];
		for(int i=chs+1; i<=n; ++i) rs[i] = !b[i][1];
		
		printf("YES\n");
		for(int i=1; i<=n; ++i) printf("%d",rs[i]);
		putchar('\n');
		for(int i=1; i<=m; ++i) printf("%d",cs[i]);
		return 0;
	}
	printf("NO");
	return 0;
}
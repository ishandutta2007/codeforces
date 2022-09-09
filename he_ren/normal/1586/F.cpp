#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int clr[MAXN][MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	int ans = 0;
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
		{
			int x = 0, ii = i, jj = j;
			while(ii != jj) ++x, ii /= d, jj /= d;
			clr[i][j] = x;
			ans = max(ans, x);
		}
	
	printf("%d\n",ans);
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			printf("%d ",clr[i][j]);
	return 0;
}
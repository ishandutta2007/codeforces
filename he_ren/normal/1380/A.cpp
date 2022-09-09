#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int p[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&p[i]);
	
	for(int i=2; i<n; ++i)
		if(p[i-1] < p[i] && p[i] > p[i+1])
		{
			printf("YES\n");
			printf("%d %d %d\n",i-1,i,i+1);
			return;
		}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
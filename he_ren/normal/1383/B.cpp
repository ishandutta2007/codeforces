#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int k=30; k>=0; --k)
	{
		int cnt1 = 0;
		for(int i=1; i<=n; ++i)
			if((a[i] >> k)&1) ++cnt1;
		
		if(cnt1%2 == 0) continue;
		
		if(n%2)
		{
			if(cnt1/2 %2 == 0) printf("WIN\n");
			else printf("LOSE\n");
		}
		else
		{
			if(cnt1/2 %2 == 0) printf("WIN\n");
			else printf("WIN\n");
		}
		return;
	}
	printf("DRAW\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
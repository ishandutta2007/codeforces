#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int cnt8 = (n+4-1)/4;
	for(int i=1; i<=n-cnt8; ++i) printf("9");
	for(int i=1; i<=cnt8; ++i) printf("8");
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
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
	if(n <= 6 + 10 + 14)
		printf("NO\n");
	else if(n == 6 + 10 + 14 + 6) printf("YES\n5 6 10 15\n");
	else if(n == 6 + 10 + 14 + 10) printf("YES\n22 6 10 %d\n",n-22-6-10);
	else if(n == 6 + 10 + 14 + 14) printf("YES\n6 7 10 21\n");
	else
		printf("YES\n"),
		printf("%d %d %d %d\n",6,10,14,n-6-10-14);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
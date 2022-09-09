#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	if(n <= 2) printf("1\n");
	else
	{
		printf("%d\n",(n-2 - 1)/x + 2);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
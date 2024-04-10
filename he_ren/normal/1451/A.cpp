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
	if(n==1) printf("0\n");
	else if(n==2) printf("1\n");
	else if(n==3) printf("2\n");
	else if(n&1) printf("3\n");
	else printf("2\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
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
	
	if(n%3 == 0) printf("%d 0 0\n",n/3);
	if(n%3 == 1)
	{
		if(n < 7) printf("-1\n");
		else printf("%d 0 1\n",(n-7)/3);
	}
	if(n%3 == 2)
	{
		if(n < 5) printf("-1\n");
		else printf("%d 1 0\n",(n-5)/3);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
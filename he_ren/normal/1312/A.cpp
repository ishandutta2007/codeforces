#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(n%m) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
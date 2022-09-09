#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int a[MAXN];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
		
		if(n==1 && (a[1]&1)) printf("-1\n");
		else if(!(a[1]&1)) printf("1\n1\n");
		else if(!(a[2]&1)) printf("1\n2\n");
		else printf("2\n1 2\n");
	}
	return 0;
}
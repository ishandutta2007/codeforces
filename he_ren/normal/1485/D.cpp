#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=m; ++j)
		{
			int x;
			scanf("%d",&x);
			
			if((i+j)%2) printf("720720 ");
			else printf("%d ",720720 - x * x * x * x);
		}
	return 0;
}
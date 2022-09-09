#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	printf("%d\n",3*(n+1) + 1);
	for(int i=0; i<=n; ++i)
		printf("%d %d\n",i,i),
		printf("%d %d\n",i+1,i),
		printf("%d %d\n",i,i+1);
	printf("%d %d\n",n+1,n+1);
	return 0;
}
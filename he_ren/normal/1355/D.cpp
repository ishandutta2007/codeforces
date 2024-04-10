#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	if(n*2 <= s)
	{
		printf("YES\n");
		for(int i=1; i<n; ++i) printf("2 ");
		printf("%d\n%d\n",s-(n-1)*2,1);
		return 0;
	}
	printf("NO\n");
	return 0;
}
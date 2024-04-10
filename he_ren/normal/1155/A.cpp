#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<n; ++i)
	{
		if(s[i+1] < s[i])
		{
			printf("YES\n%d %d",i,i+1);
			return 0;
		}
	}
	printf("NO");
	return 0;
}
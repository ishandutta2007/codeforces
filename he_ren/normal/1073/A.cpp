#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			if(s[i]!=s[j])
			{
				printf("YES\n%c%c",s[i],s[j]);
				return 0;
			}
	printf("NO");
	return 0;
}
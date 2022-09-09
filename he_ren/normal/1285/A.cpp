#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int l=0;
	for(int i=1; i<=n; ++i)
		if(s[i]=='L') ++l;
	int r=n-l;
	printf("%d",l+r+1);
	return 0;
}
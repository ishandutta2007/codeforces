#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	printf("3\n");
	printf("L 2\n");
	printf("R 2\n");
	printf("R %d\n",n+1 + n-1 -1);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}
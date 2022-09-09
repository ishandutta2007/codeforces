#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	
	int n = strlen(s+1);
	putchar(s[1]);
	for(int i=2; i<n; i+=2) putchar(s[i]);
	putchar(s[n]);
	
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	sort(s+1,s+n+1);
	printf("%s\n",s+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
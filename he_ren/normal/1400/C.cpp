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
	int x;
	scanf("%s%d",s+1,&x);
	int n = strlen(s+1);
	
	static int a[MAXN];
	for(int i=1; i<=n; ++i) a[i] = 1;
	
	for(int i=1; i<=n; ++i) if(s[i] == '0')
	{
		if(i-x >= 1) a[i-x] = 0;
		if(i+x <= n) a[i+x] = 0;
	}
	
	for(int i=1; i<=n; ++i) if(s[i] == '1')
	{
		bool flag = 0;
		if(i-x >= 1 && a[i-x]) flag = 1;
		if(i+x <= n && a[i+x]) flag = 1;
		if(!flag)
		{
			printf("-1\n");
			return;
		}
	}
	
	for(int i=1; i<=n; ++i) putchar(a[i] + '0');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
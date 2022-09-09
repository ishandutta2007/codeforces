#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e2 + 5;

char t[MAXN];

void solve(void)
{
	scanf("%s",t+1);
	int n = strlen(t+1);
	
	bool flag=1;
	for(int i=2; i<=n; ++i)
		if(t[i] != t[i-1])
		{
			flag=0;
			break;
		}
	if(flag){ printf("%s\n",t+1); return;}
	
	for(int i=1; i<=n; ++i)
		printf("01");
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
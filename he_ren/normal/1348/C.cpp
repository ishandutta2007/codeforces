#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	sort(s+1,s+n+1);
	
	for(int i=1; i<d; ++i)
		if(s[i] < s[d])
		{
			printf("%c\n",s[d]);
			return;
		}
	
	putchar(s[d]);
	for(int i=1; i+d<=n; ++i)
		s[i] = s[i+d];
	n -= d;
	
	bool flag=1;
	for(int i=2; i<=n; ++i)
		if(s[i]!=s[i-1]) flag=0;
	if(flag)
	{
		int tmp = (n+d-1)/d;
		while(tmp--) putchar(s[1]);
		putchar('\n');
		return;
	}
	
	for(int i=1; i<=n; ++i) putchar(s[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
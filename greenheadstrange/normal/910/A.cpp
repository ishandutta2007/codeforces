#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define maxn 105
using namespace std; 
char s[maxn];
int n, d;
int main()
{
	scanf("%d%d", &n, &d);
	scanf("%s", s + 1);
	int pl = 1;
	int ans = 0;
	while(pl < n)
	{
		int npl = 0;
		for(int j = pl + 1; j <= pl + d && j <= n; j++)
			if(s[j] == '1') npl = j;
		pl = npl;
		ans++;
		if(!npl)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
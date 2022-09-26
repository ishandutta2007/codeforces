#include <bits/stdc++.h>

using namespace std;

int T,n;

char s[20];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		int MAX = 0;
		for (int i = 1;i <= n;i++)
			MAX = max(MAX,s[i] - '0');
		printf("%d\n",MAX);
	}
	return 0;
}
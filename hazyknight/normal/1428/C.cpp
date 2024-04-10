#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int T,n,top;

char s[MAXN];
char S[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		top = 0;
		for (int i = 1;i <= n;i++)
		{
			if (s[i] == 'A')
				S[++top] = 'A';
			else
			{
				if (top >= 1 && S[top] == 'A')
					top--;
				else
					S[++top] = 'B';
			}
		}
		n = top;
		for (int i = 1;i <= top;i++)
			s[i] = S[i];
		top = 0;
		for (int i = 1;i <= n;i++)
		{
			if (s[i] == 'A')
				S[++top] = 'A';
			else
			{
				if (top >= 1 && S[top] == 'B')
					top--;
				else
					S[++top] = 'B';
			}
		}
		printf("%d\n",top);
	}
	return 0;
}
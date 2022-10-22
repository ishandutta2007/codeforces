#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100005
using namespace std;
int T, n;
char s[maxn];
void solve()
{
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++)
	{
		if(s[i] != '?')
		{
			for (int j = i + 1; j <= n; j++)
			{
				if(s[j] != '?') continue;
				if(s[j - 1] == 'R') s[j] = 'B';
				else s[j] = 'R';
			}
			for (int j = i - 1; j >= 1; j--)
			{
				if(s[j] != '?') continue;
				if(s[j + 1] == 'R') s[j] = 'B';
				else s[j] = 'R';
			}
			break;
		}
		if(i == n) 
		{
			for (int i = 1; i <= n; i++)
			{
				if(i & 1) s[i] = 'B';
				else s[i] = 'R';
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
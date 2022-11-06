#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 5000 + 5

int n, ans, Ok[N][N];
char s[N];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i ++)
	{
		int sum = 0;
		for (int j = i; j < n; j ++)
		{
			if (s[j] == '(' || s[j] == '?') sum ++;
			else sum --;
			if (sum < 0) break ;
			Ok[i][j] ++;
		}
	}
	for (int i = n - 1; ~i; i --)
	{
		int sum = 0;
		for (int j = i; ~j; j --)
		{
			if (s[j] == ')' || s[j] == '?') sum ++;
			else sum --;
			if (sum < 0) break ;
			Ok[j][i] ++;
		}
	}
	for (int i = 0; i < n; i ++)
		for (int j = i + 1; j < n; j += 2)
			if (Ok[i][j] == 2) ans ++;
	printf("%d\n", ans);
	return 0;
}
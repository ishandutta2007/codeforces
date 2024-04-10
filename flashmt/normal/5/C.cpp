#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[1000100];
int n, st[1000100], last, s[1000100], ans, ways = 1;

int main()
{
	scanf("%s", a);
	n = strlen(a);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (a[i - 1] == '(' ? 1 : -1);
	
	st[last = 1] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (last && s[st[last]] > s[i]) last--;
		if (last && s[st[last]] == s[i])
		{
			if (i - st[last] > ans) ans = i - st[last], ways = 1;
			else ways += (i - st[last] == ans);
		}
		else st[++last] = i;
	}
	
	cout << ans << ' ' << ways << endl;
}
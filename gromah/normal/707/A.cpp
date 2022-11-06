#include <cstdio>

int n, m;
bool ok = 1;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++)
	{
		char ch = '\n';
		for (ch = getchar(); ch < 'A' || ch > 'Z'; ch = getchar()) ;
		ok &= (ch == 'B' || ch == 'W' || ch == 'G');
	}
	if (ok) puts("#Black&White");
		else puts("#Color");
	return 0;
}
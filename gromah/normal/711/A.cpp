#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000 + 5

int n;
char s[N][9];
bool ok = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", s[i]);
		if (s[i][0] == 'O' && s[i][1] == 'O' && !ok)
		{
			ok = 1;
			s[i][0] = s[i][1] = '+';
		}
		if (s[i][3] == 'O' && s[i][4] == 'O' && !ok)
		{
			ok = 1;
			s[i][3] = s[i][4] = '+';
		}
	}
	if (!ok) puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= n; i ++)
			printf("%s\n", s[i]);
	}
	return 0;
}
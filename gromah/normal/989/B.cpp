#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5

int n, p;
char s[N];
bool flag = 1;

int main()
{
	scanf("%d%d", &n, &p);
	scanf("%s", s);
	for (int i = 0; flag && i < n - p; i ++)
		flag = (s[i] == s[i + p] && s[i] != '.');
	if (flag) puts("No");
	else
	{
		for (int i = 0; i < n; i ++)
			if (s[i] == '.')
			{
				if (i >= p)
					s[i] = s[i - p] ^ 1;
				else if (i + p < n && s[i + p] != '.')
					s[i] = s[i + p] ^ 1;
				else s[i] = '0';
			}
		printf("%s\n", s);
	}
	return 0;
}
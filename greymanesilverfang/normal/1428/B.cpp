#include <cstdio>
const int MAX = 4e5;
char s[MAX];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n; scanf("%d%s", &n, &s[1]);
		bool cw = false, ccw = false;
		int noreturn = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (s[i] == '>')
				cw = true;
			if (s[i] == '<')
				ccw = true;
			if (s[i] != '-' && s[i % n + 1] != '-')
				++noreturn;
		}
		if (cw && ccw)
			printf("%d\n", n - noreturn);
		else 
			printf("%d\n", n);
	}
}
#include <cstdio>
char s[200];
int sum, cntz, cnte;

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		sum = cntz = cnte = 0;
		for (int i = 0; s[i]; ++i)
		{
			int x = s[i] - '0';
			sum += x;
			cntz += x == 0;
			cnte += x % 2 == 0;
		}
		printf("%s\n", sum % 3 == 0 && cntz > 0 && cnte > 1 ? "red" : "cyan");
	}
}
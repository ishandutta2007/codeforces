#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, Max;
char s[N << 1];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i ++)
		s[i + n] = s[i];
	n <<= 1;
	for (int i = 0, cur = 0; i < n; i ++)
	{
		if (!i || s[i] != s[i - 1])
			cur ++;
		else cur = 1;
		Max = max(Max, cur);
	}
	printf("%d\n", min(Max, n >> 1));
	return 0;
}
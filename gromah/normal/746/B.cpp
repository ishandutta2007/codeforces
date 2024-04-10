#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5

int n;
char s[N], Ans[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	if (n & 1) Ans[n >> 1] = s[0];
	for (int i = 0; i < (n >> 1); i ++)
	{
		Ans[i] = s[n - (i + 1) * 2];
		Ans[n - i - 1] = s[n - (i + 1) * 2 + 1];
	}
	printf("%s\n", Ans);
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 20 + 5

int len;
char s[N];
LL x, ans;

inline int Trans(char ch)
{
	if (ch > 'c') return 'g' - ch;
	return ch - 'a' + 4;
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len - 1; i ++)
		x = x * 10 + s[i] - '0';
	ans = (x - 1) / 4 * 16, x -= (x - 1) / 4 * 4;
	if (x > 2) x -= 2;
	ans += (x - 1) * 7;
	ans += Trans(s[len - 1]);
	printf("%I64d\n", ans);
	return 0;
}
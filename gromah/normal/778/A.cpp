#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int len, _len, P[N], Dp[N];
char s[N], t[N];
bool Flag[N];

bool Check(int k)
{
	for (int i = 1; i <= len; i ++)
		Flag[i] = 0;
	for (int i = 1; i <= k; i ++)
		Flag[P[i]] = 1;
	Dp[0] = 0;
	for (int i = 1; i <= len; i ++)
	{
		Dp[i] = Dp[i - 1];
		if (Flag[i] || Dp[i] == _len) continue ;
		if (s[i] == t[Dp[i] + 1]) Dp[i] ++;
	}
	return Dp[len] == _len;
}

int main()
{
	scanf("%s%s", s + 1, t + 1);
	len = strlen(s + 1), _len = strlen(t + 1);
	for (int i = 1; i <= len; i ++)
		scanf("%d", P + i);
	int l = 0, r = len - _len;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (Check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
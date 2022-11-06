#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int m, len, Len, head, tail, sz, q[N], Min[N], Pos[N];
char s[N], Ans[N];

int main()
{
	scanf("%d", &m);
	scanf("%s", s);
	len = strlen(s), head = 0, tail = 0;
	m = min(m, len);
	char Max = 'a';
	for (int i = 0; i < len; i ++)
	{
		for (; head < tail && q[head] + m <= i; head ++) ;
		for (; head < tail && s[q[tail - 1]] >= s[i]; tail --) ;
		q[tail ++] = i;
		Min[i] = q[head];
		if (i >= m - 1) Max = max(Max, s[Min[i]]);
	}
	for (int i = 0; i < len; i ++)
	{
		if (s[i] < Max)
			Ans[Len ++] = s[i];
		else if (s[i] == Max) Pos[++ sz] = i;
	}
	for (int i = 0, last = -1; i < len; i ++)
	{
		if (s[i] < Max) last = i;
		else if (i - last == m)
		{
			int t = lower_bound(Pos + 1, Pos + sz + 1, i + 1) - Pos - 1;
			last = Pos[t];
			Ans[Len ++] = Max;
		}
	}
	sort(Ans, Ans + Len);
	printf("%s", Ans);
	return 0;
}
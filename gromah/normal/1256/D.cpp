#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int Case, n;
char s[N];
LL k;

int Find(const char *p, char ch)
{
	int i;
	for (i = 0; p[i]; i ++)
		if (p[i] == ch)
			return i;
	return i;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%lld", &n, &k);
		scanf("%s", s);
		s[n] = '1';
		for (int i = Find(s, '1'), cnt = 1; i < n && k; i ++, cnt ++)
		{
			int j = Find(s + i + 1, '1') + i + 1;
			int t = min(LL(j - i - 1), k / cnt);
			k -= t * cnt;
			for (int l = 1; l <= t; l ++)
				swap(s[i + l - cnt], s[i + l]);
			if (t < j - i - 1)
			{
				for (int l = i + t + 1; k; k --, l --)
					swap(s[l], s[l - 1]);
			}
			i += t;
		}
		s[n] = '\0';
		printf("%s\n", s);
	}
	return 0;
}
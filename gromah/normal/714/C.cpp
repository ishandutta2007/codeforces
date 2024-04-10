#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define M 2000000 + 5

int n, tot, Trie[M][2], Num[M];
LL x;
char s[9], ch[20];

int main()
{
	for (scanf("%d", &n); n; n --)
	{
		scanf("%s", s);
		if (s[0] == '?')
		{
			scanf("%s", ch);
			int len = strlen(ch), u = 0, ans;
			for (int i = 1; i <= 19; i ++)
			{
				int j = 0;
				if (i <= len)
				{
					j = ch[len - i] - '0';
					ch[len - i] = '\0';
				}
				if (!Trie[u][j])
				{
					u = -1;
					break ;
				}
				u = Trie[u][j];
			}
			if (!~u) ans = 0;
				else ans = Num[u];
			printf("%d\n", ans);
		}
		else
		{
			scanf("%I64d", &x);
			for (int i = 0, u = 0; i <= 18 || x; i ++, x /= 10)
			{
				int j = (x % 10) & 1;
				if (!Trie[u][j])
					Trie[u][j] = ++ tot;
				u = Trie[u][j];
				Num[u] += (s[0] == '+' ? 1 : -1);
			}
		}
	}
	return 0;
}
#include <cstdio>
#define N 7000000 + 5
#define LOGN 30

int q, x, tot, Trie[N][2], Size[N];
char s[9];

int main()
{
	for (scanf("%d", &q); q; q --)
	{
		scanf("%s%d", s, &x);
		if (s[0] == '+' || s[0] == '-')
		{
			for (int i = LOGN, u = 0; ~i; i --)
			{
				int j = (x >> i) & 1;
				if (!Trie[u][j])
					Trie[u][j] = ++ tot;
				u = Trie[u][j];
				Size[u] += (s[0] == '+' ? 1 : -1);
			}
		}
		else
		{
			int res = 0;
			for (int i = LOGN, u = 0; ~i; i --)
			{
				int j = (x >> i) & 1;
				if (Trie[u][j ^ 1] && Size[Trie[u][j ^ 1]])
				{
					u = Trie[u][j ^ 1];
					res += (1 << i);
				}
				else if (Trie[u][j])
					u = Trie[u][j];
				else break;
			}
			res = res > x ? res : x;
			printf("%d\n", res);
		}
	}
	return 0;
}
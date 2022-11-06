#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5
#define M 10000000 + 5
#define LOGN 29

int n, tot, A[N], Trie[M][2], Cnt[M];

void Add(int x)
{
	int u = 0;
	for (int i = LOGN; ~i; i --)
	{
		int d = (x >> i) & 1;
		if (!Trie[u][d])
			Trie[u][d] = ++ tot;
		u = Trie[u][d];
		Cnt[u] ++;
	}
}

int Calc(int x)
{
	int u = 0, cur = 0;
	for (int i = LOGN; ~i; i --)
	{
		int d = (x >> i) & 1;
		if (Trie[u][d] && Cnt[Trie[u][d]])
		{
			u = Trie[u][d];
			cur |= (d << i);
		}
		else
		{
			u = Trie[u][d ^ 1];
			cur |= ((d ^ 1) << i);
		}
		Cnt[u] --;
	}
	return cur ^ x;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		Add(x);
	}
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Calc(A[i]), i == n ? '\n' : ' ');
	return 0;
}
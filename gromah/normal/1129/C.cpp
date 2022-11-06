#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 3000 + 5
#define M 4600000 + 5
#define Mod 1000000007

int n, sum, tot, Cur[N], Trie[M][2], Fa[M], Dp[M];
const string banned[4] = {"1100", "1010", "0111", "1111"};

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

inline int Get(int x)
{
	return Trie[Fa[x]][1] == x;
}

inline bool Check(const string &str)
{
	for (const string& bs : banned)
		if (bs == str)
			return 0;
	return 1;
}

int Calc(int x)
{
	string t;
	int res = 0;
	for (int u = x, l = 1; u && l <= 4; u = Fa[u], l ++)
	{
		t.push_back('0' + Get(u));
		if (l <= 3 || Check(t))
			res = Inc(res, Dp[Fa[u]]);
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	Dp[0] = 1;
	for (int i = 1, d; i <= n; i ++)
	{
		scanf("%d", &d);
		for (int j = 1; j <= i; j ++)
		{
			if (!Trie[Cur[j]][d])
			{
				Trie[Cur[j]][d] = ++ tot;
				Fa[tot] = Cur[j];
				sum = Inc(sum, Dp[tot] = Calc(tot));
			}
			Cur[j] = Trie[Cur[j]][d];
		}
		printf("%d\n", sum);
	}
	return 0;
}
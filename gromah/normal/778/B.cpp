#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 5000 + 5
#define M 1000 + 5
#define T 100000 + 5

int n, m, tot, Trie[T][26], Num[T], Num_1[N], Op[N], Num_2[N], Val[N][M], Max[M], Min[M];
bool Flag[N];
char s[N];

inline int Expose(char *ch, int id)
{
	int len = strlen(ch), u = 0;
	for (int i = 0; i < len; i ++)
	{
		int d = ch[i] - 'a';
		if (!Trie[u][d])
			Trie[u][d] = ++ tot;
		u = Trie[u][d];
	}
	if (id) Num[u] = id;
	return Num[u];
}

inline int Calc(int w)
{
	int res = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (!Flag[i])
		{
			if (Op[i] == 0) Val[i][w] = (Val[Num_1[i]][w] & Val[Num_2[i]][w]);
			else if (Op[i] == 1) Val[i][w] = (Val[Num_1[i]][w] ^ Val[Num_2[i]][w]);
			else Val[i][w] = (Val[Num_1[i]][w] | Val[Num_2[i]][w]);
		}
		res += Val[i][w];
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", s);
		Expose(s, i);
		scanf("%s", s);
		scanf("%s", s);
		if (s[0] == '0' || s[0] == '1')
		{
			Flag[i] = 1;
			for (int j = 0; j < m; j ++)
				Val[i][j] = s[j] - '0';
		}
		else
		{
			Flag[i] = 0;
			if (s[0] == '?') Num_1[i] = n + 1;
			else Num_1[i] = Expose(s, 0);
			scanf("%s", s);
			if (s[0] == 'A') Op[i] = 0;
			else if (s[0] == 'X') Op[i] = 1;
			else Op[i] = 2;
			scanf("%s", s);
			if (s[0] == '?') Num_2[i] = n + 1;
			else Num_2[i] = Expose(s, 0);
		}
	}
	for (int i = 0; i < m; i ++)
	{
		Val[n + 1][i] = 0;
		int tmp_0 = Calc(i);
		Val[n + 1][i] = 1;
		int tmp_1 = Calc(i);
		if (tmp_0 > tmp_1) Max[i] = 0, Min[i] = 1;
		else if (tmp_0 == tmp_1) Max[i] = Min[i] = 0;
		else Max[i] = 1, Min[i] = 0;
	}
	for (int i = 0; i < m; i ++)
		printf("%d", Min[i]);
	puts("");
	for (int i = 0; i < m; i ++)
		printf("%d", Max[i]);
	puts("");
	return 0;
}
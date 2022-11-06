#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5
#define M 10000 + 5
#define mp make_pair

int n, Min, cnt, tot, A[N], _A[N], Ord[N], Op[M][6];
char s[N];

inline bool cmp(int u, int v)
{
	return mp(_A[u], u) > mp(_A[v], v);
}

inline bool Check(int k)
{
	cnt = tot = 0;
	for (int i = 1; i <= n; i ++)
	{
		tot += A[i] - k;
		_A[i] = A[i];
		Ord[i] = i;
	}
	if (!tot) return 1;
	sort(Ord + 1, Ord + n + 1, cmp);
	if (tot & 1)
	{
		if (n < 5) return 0;
		Op[++ cnt][0] = 5;
		for (int i = 1; i <= 5; i ++)
		{
			if (_A[Ord[i]] == k) return 0;
			_A[Ord[i]] --;
			Op[cnt][i] = Ord[i];
		}
		sort(Ord + 1, Ord + n + 1, cmp);
		tot -= 5;
	}
	for (; tot; tot -= 2)
	{
		Op[++ cnt][0] = 2;
		for (int i = 1; i <= 2; i ++)
		{
			if (_A[Ord[i]] == k) return 0;
			_A[Ord[i]] --;
			Op[cnt][i] = Ord[i];
		}
		sort(Ord + 1, Ord + n + 1, cmp);
	}
	return 1;
}

inline void Output(int ans)
{
	printf("%d\n", ans);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++)
	{
		for (int j = 1; j <= n; j ++)
			s[j] = '0';
		for (int j = 1; j <= Op[i][0]; j ++)
			s[Op[i][j]] = '1';
		printf("%s\n", s + 1);
	}
}

inline void Brute()
{
	puts("0");
	printf("%d\n", n * 100);
	for (int i = 1; i <= n; i ++)
	{
		int _i = i == n ? 1 : i + 1;
		for (int j = 1; j <= n; j ++)
			s[j] = '0';
		s[i] = s[_i] = '1';
		for (int j = 1; j <= 100; j ++)
			printf("%s\n", s + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Min = i == 1 ? A[i] : min(Min, A[i]);
	}
	if (Check(Min)) Output(Min);
	else if (Min && Check(Min - 1)) Output(Min - 1);
	else Brute();
	return 0;
}
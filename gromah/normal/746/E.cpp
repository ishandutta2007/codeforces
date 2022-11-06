#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, m, odd, even, cnt, t_o = 1, t_e = 2, A[N], Ord[N];
map <int, bool> Flag;

inline bool cmp(int u, int v)
{
	return A[u] < A[v];
}

inline int Get(int op)
{
	cnt ++;
	int &x = op ? t_o : t_e;
	for (; Flag[x] && x <= m; x += 2) ;
	if (x > m) return -1;
	Flag[x] = 1;
	return x;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Ord[i] = i;
		Flag[A[i]] = 1;
		if (A[i] & 1) odd ++;
		else even ++;
	}
	sort(Ord + 1, Ord + n + 1, cmp);
	bool ok = 1;
	for (int i = 1; ok && i < n; i ++)
	{
		int _i = Ord[i];
		if (A[_i] != A[Ord[i + 1]]) continue ;
		if ((A[_i] & 1) && odd > even)
		{
			A[_i] = Get(0);
			odd --, even ++;
		}
		else if (A[_i] & 1)	A[_i] = Get(1);
		else if (even > odd)
		{
			A[_i] = Get(1);
			odd ++, even --;
		}
		else A[_i] = Get(0);
		if (!~A[_i]) ok = 0;
	}
	for (int i = 1; ok && odd != even && i <= n; i ++)
	{
		if ((A[i] & 1) && odd > even)
		{
			A[i] = Get(0);
			odd --, even ++;
		}
		else if ((A[i] + 1 & 1) && even > odd)
		{
			A[i] = Get(1);
			odd ++, even --;
		}
		if (!~A[i]) ok = 0;
	}
	if (!ok) puts("-1");
	else
	{
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i ++)
			printf("%d%c", A[i], i == n ? '\n' : ' ');
	}
	return 0;
}
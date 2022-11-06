#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000 + 5

int n, q, A[N], Next[N], L[N], R[N], Ord[N], Ans[N], T[N], Sum[N];
bool Ok[N];

inline int getint()
{
	char ch = '\n';
	for (; ch > '9' || ch < '0'; ch = getchar()) ;
	int res = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

inline bool cmp(int u, int v)
{
	return make_pair(A[u], u) < make_pair(A[v], v);
}

inline bool _cmp(int u, int v)
{
	return L[u] < L[v];
}

inline void Modify(int x, int k)
{
	for (; x <= n; x += (x & -x))
		T[x] ^= k;
}

inline int Query(int x)
{
	int res = 0;
	for (; x; x -= (x & -x))
		res ^= T[x];
	return res;
}

inline void Prepare()
{
	for (int i = 1; i <= n; i ++)
		if (Ok[i]) Modify(i, A[i]);
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; i ++)
	{
		A[i] = getint();
		Ord[i] = i, Ok[i] = 1;
		Sum[i] = Sum[i - 1] ^ A[i];
	}
	sort(Ord + 1, Ord + n + 1, cmp);
	for (int i = 1; i <= n; i ++)
		if (i != n && A[Ord[i]] == A[Ord[i + 1]])
			Ok[Next[Ord[i]] = Ord[i + 1]] = 0;
		else Next[Ord[i]] = n + 1;
	Prepare();
	q = getint();
	for (int i = 1; i <= q; i ++)
	{
		L[i] = getint(), R[i] = getint();
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + q + 1, _cmp);
	for (int i = 1, t = 1; i <= n; i ++)
	{
		for (; t <= q && L[Ord[t]] == i; t ++)
			Ans[Ord[t]] = Sum[L[Ord[t]] - 1] ^ Sum[R[Ord[t]]] ^ Query(R[Ord[t]]);
		Modify(i, A[i]);
		Modify(Next[i], A[i]);
	}
	for (int i = 1; i <= q; i ++)
		printf("%d\n", Ans[i]);
	return 0;
}
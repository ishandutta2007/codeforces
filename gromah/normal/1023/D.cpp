#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, q, A[N], L[N], R[N], Next[N], Tree[N], Pos[N];
vector <int> Vec[N];
set <int> Set;

void Add(int x, int k)
{
	for (; x <= n; x += (x & -x))
		Tree[x] += k;
}

int Calc(int x)
{
	int res = 0;
	for (; x; x -= (x & -x))
		res += Tree[x];
	return res;
}

bool Check()
{
	if (!L[q])
	{
		bool ok = 0;
		for (int i = 1; !ok && i <= n; i ++)
			if (!A[i]) A[i] = q, ok = 1, L[q] = R[q] = i, Vec[q].push_back(i), Set.erase(i), Add(i, -1);
		if (!ok) return 0;
	}
	for (int i = q; i; i --)
	{
		if (!L[i]) continue ;
		for (int d : Vec[i])
			Add(d, 1);
		int s = Calc(R[i]) - Calc(L[i] - 1);
		if (s != R[i] - L[i] + 1) return 0;
		int sz = 0;
		for (set <int> :: iterator b = Set.lower_bound(L[i]), e = Set.upper_bound(R[i]); b != e; b ++)
			Pos[++ sz] = *b, A[*b] = i;
		for (int i = 1; i <= sz; i ++)
			Set.erase(Pos[i]);
	}
	for (int i = 1; i <= n; i ++)
		if (!A[i]) A[i] = 1;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		if (!A[i])
		{
			Add(i, 1);
			Set.insert(i);
		}
		else
		{
			if (!L[A[i]]) L[A[i]] = i;
			R[A[i]] = i;
			Vec[A[i]].push_back(i);
		}
	}
	bool ok = Check();
	if (!ok) puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= n; i ++)
			printf("%d%c", A[i], i == n ? '\n' : ' ');
	}
	return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, m, ans, A[N], Rank[N];
vector <int> Vec[N];
bool Flag[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, p; i <= n; i ++)
	{
		scanf("%d", A + i);
		Rank[A[i]] = i;
	}
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
	}
	for (int i = n - 1; i; i --)
	{
		int cnt = 0;
		for (int d : Vec[A[i]])
			if (Rank[d] > i && !Flag[d])
				cnt ++;
		if (i + cnt + ans == n)
			ans ++, Flag[A[i]] = 1;
	}
	printf("%d\n", ans);
	return 0;
}
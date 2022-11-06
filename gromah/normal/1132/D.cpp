#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define INF 10000000000000LL

int n, m, B[N], C[N];
LL A[N];
vector <int> Vec[N];

bool Check(LL k)
{
	if (k == 1)
	{
		volatile int x = 0;
		x = 1;
	}
	int ret = 0;
	for (int i = 0; i < m; i ++)
		Vec[i].clear();
	for (int i = 1; i <= n; i ++)
	{
		LL ti = A[i] / B[i];
		C[i] = 0;
		if (ti < m - 1)
			Vec[ti].push_back(i);
	}
	for (int i = 0, ret = 0; i < m; i ++)
	{
		ret ++;
		while (!Vec[i].empty())
		{
			int d = Vec[i].back();
			Vec[i].pop_back();
			if (!ret) return false;
			ret --, C[d] ++;
			LL ti = (k * C[d] + A[d]) / B[d];
			if (ti < m - 1)
				Vec[ti].push_back(d);
		}
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", A + i);
	for (int i = 1; i <= n; i ++)
		scanf("%d", B + i);
	LL l = 0, r = INF;
	while (l < r)
	{
		LL mid = l + r >> 1;
		if (Check(mid))
			r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l == INF ? -1 : l);
	return 0;
}
#include <cstdio>
#include <map>
#include <utility>
const int N = 3e5;
int a[N];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += a[i];
	std::map<std::pair<int,int>,int> bonus;
	int q; scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int s, t, u; scanf("%d%d%d", &s, &t, &u);
		int &x = bonus[{s, t}];
		if (x != 0 && ++a[x] > 0)
			++sum;
		x = u;
		if (x != 0 && 0 < a[x]--)
			--sum;
		printf("%lld\n", sum);
	}
}
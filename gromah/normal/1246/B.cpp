#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, k, A[N], F[N], q[N];
LL t, ans;
vector<int> Vec;
unordered_map <int, int> Map;

void Prepare()
{
	for (int i = 2; i < N; i ++)
	{
		if (!F[i])
			F[i] = q[++ q[0]] = i;
		for (int j = 1; j <= q[0] && i * q[j] < N; j ++)
		{
			F[i * q[j]] = q[j];
			if (i % q[j] == 0)
				break ;
		}
	}
}

int main()
{
	Prepare();
	scanf("%d%d", &n, &k);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		Vec.clear();
		for (t = 1; x > 1; x /= F[x])
			Vec.push_back(F[x]);
		int _x = 1;
		for (size_t l = 0, r; l < Vec.size() && t != -1; l = r)
		{
			for (r = l; r < Vec.size() && Vec[l] == Vec[r]; r ++) ;
			for (int j = (r - l) % k; j; j --)
				_x *= Vec[l];
			for (int ret = (k - (r - l) % k) % k; ret && t != -1; ret --)
			{
				t *= Vec[l];
				if (t > N)
					t = -1;
			}
		}
		if (t <= N)
			ans += Map[t];
		Map[_x] ++;
	}
	printf("%lld\n", ans);
	return 0;
}
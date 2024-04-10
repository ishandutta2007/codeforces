#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int Case, n, x, a, y, b, A[N], W[N];
LL k;

bool Check(int pos)
{
	static int S[N];
	for (int i = 1; i <= pos; i ++)
		S[i] = W[i];
	sort(S + 1, S + pos + 1);
	reverse(S + 1, S + pos + 1);
	LL tot = 0;
	for (int i = 1; i <= pos; i ++)
		tot += 1LL * S[i] * A[i];
	return tot >= k;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", A + i);
			A[i] /= 100, W[i] = 0;
		}
		scanf("%d%d%d%d%I64d", &x, &a, &y, &b, &k);
		for (int i = a; i <= n; i += a)
			W[i] += x;
		for (int i = b; i <= n; i += b)
			W[i] += y;
		sort(A + 1, A + n + 1);
		reverse(A + 1, A + n + 1);
		int l = 1, r = n + 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (Check(mid))
				r = mid;
			else l = mid + 1;
		}
		if (l <= n)
			printf("%d\n", l);
		else puts("-1");
	}
	return 0;
}
#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10000 + 5
#define M 2000 + 5

int Case, n, A[N];
bitset<M> B, MD;

bool Check(int len)
{
	for (int i = 0; i <= len; i ++)
		MD[i] = true;
	for (int i = len + 1; i < M; i ++)
		MD[i] = false;
	B = MD;
	for (int i = 1; i <= n; i ++)
		B = ((B << A[i]) | (B >> A[i])) & MD;
	for (int i = 0; i <= len; i ++)
		if (B[i] == true)
			return true;
	return false;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", A + i);
		int l = 1, r = 2000;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (Check(mid))
				r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define M 32

int n, B[N], C[N];
LL sum, A[N], Num[M];

inline bool Check()
{
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < M; j ++)
			if ((A[i] >> j) & 1) Num[j] ++;
	for (int i = 1; i <= n; i ++)
	{
		LL t_b = 0, t_c = 1LL * n * A[i];
		for (int j = 0; j < M; j ++)
		{
			if ((A[i] >> j) & 1)
				t_b += Num[j] << j;
			else t_c += Num[j] << j;
		}
		if (t_b != B[i] || t_c != C[i]) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", B + i);
		sum += B[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", C + i);
		sum += C[i];
	}
	if (sum % (n * 2)) puts("-1");
	else
	{
		sum /= n * 2;
		bool ok = 1;
		for (int i = 1; ok && i <= n; i ++)
		{
			A[i] = (B[i] + C[i] - sum) / n;
			ok = (B[i] + C[i] >= sum && ((B[i] + C[i] - sum) % n == 0));
		}
		if (ok) ok = Check();
		if (!ok) puts("-1");
		else for (int i = 1; i <= n; i ++)
			printf("%I64d%c", A[i], i == n ? '\n' : ' ');
	}
	return 0;
}
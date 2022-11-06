#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5
#define LIM 1234567890987654321LL

int n, k, m, A[N];
LL sum, Q[N];

inline int getint()
{
	char ch = '\n';
	for (; ch > '9' || ch < '0'; ch = getchar()) ;
	int res = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

inline bool Check(LL x)
{
	LL res = 0;
	for (Q[m = 0] = x; Q[m] < LIM; m ++)
		Q[m + 1] = Q[m] * 2;
	for (int i = 1, t = 0; i <= n; i ++)
	{
		for (; Q[t] <= A[i]; t ++) ;
		res += t ? max(1LL << t - 1, (1LL << t) - (Q[t] - A[i])) : 0;
	}
	return res >= k;
}

int main()
{
	n = getint(), k = getint();
	for (int i = 1; i <= n; i ++)
		sum += (A[i] = getint());
	sort(A + 1, A + n + 1);
	LL l = 0, r = sum / k;
	while (l < r)
	{
		LL mid = l + r + 1 >> 1;
		if (Check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%I64d\n", l ? l : -1LL);
	return 0;
}
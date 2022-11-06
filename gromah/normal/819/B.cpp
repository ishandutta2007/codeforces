#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5
#define INF 1234567890987654321LL

int n, Std, _std, cnt_1, cnt_2, _cnt_1, _cnt_2, A[N], _A[N], T[N], _T[N];
LL ans = INF, del, Sum[N];
vector <int> Vec[N << 1];

inline int Abs(int x)
{
	return x > 0 ? x : -x;
}

int main()
{
	scanf("%d", &n);
	Std = 0, _std = -n;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		_A[i] = A[i] - i;
		Vec[_A[i] + n].push_back(i);
		Sum[i] = Sum[i - 1] + Abs(_A[i]);
		if (_A[i] <= 0) cnt_1 ++;
		else cnt_2 ++;
	}
	LL ans_1 = Sum[n], ans_2 = 0;
	for (int d = 0; d < n; d ++)
	{
		LL tmp = ans_1 + ans_2;
		if (tmp < ans) ans = ans_1 + ans_2, del = d;
		
		ans_1 -= Abs(_A[n - d] - Std);
		if (_A[n - d] <= Std) cnt_1 --;
		else cnt_2 --;
		ans_1 += cnt_1 - cnt_2;
		Std ++;
		for (int i = 0; i < Vec[Std + n].size(); i ++)
		{
			int x = Vec[Std + n][i];
			if (x < n - d) cnt_1 ++, cnt_2 --;
			else break ;
		}
		
		ans_2 += _cnt_1 - _cnt_2;
		_std ++;
		ans_2 += Abs(_A[n - d] - _std);
		if (_A[n - d] <= _std) _cnt_1 ++;
		else _cnt_2 ++;
		for (int i = Vec[_std + n].size() - 1; ~i; i --)
		{
			int x = Vec[_std + n][i];
			if (x > n - d) _cnt_1 ++, _cnt_2 --;
			else break ;
		}
	}
	printf("%I64d %d\n", ans, del);
	return 0;
}
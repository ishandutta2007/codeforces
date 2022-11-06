#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define mp make_pair

int k;
LL n, cnt, m, A[N];
map <LL, LL> Map, Val;

inline LL Solve(LL x, LL &val)
{
	if (Map.find(x) != Map.end()) return val = Val[x], Map[x];
	if (x == 0) return Val[x] = val = Map[x] = 0;
	int t = upper_bound(A + 1, A + k, x) - A - 1;
	if (t == 1)	return Val[x] = val = Map[x] = x;
	LL ret1 = x - A[t], val1 = 0, res1 = Solve(ret1, val1);
	LL ret2 = A[t] - A[t - 1] - 1, val2 = 0, res2 = Solve(ret2, val2);
	if (mp(res1, val1 + A[t]) > mp(res2, val2 + A[t - 1]))
	{
		Val[x] = val = val1 + A[t];
		Map[x] = res1 + 1;
	}
	else
	{
		Val[x] = val = val2 + A[t - 1];
		Map[x] = res2 + 1;
	}
	return Map[x];
}

int main()
{
	cin >> n;
	for (k = 1; 1LL * k * k * k <= n; k ++)
		A[k] = 1LL * k * k * k;
	cnt = Solve(n, m);
	cout << cnt << ' ' << m << endl;
	return 0;
}
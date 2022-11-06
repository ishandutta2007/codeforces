#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long uLL;
typedef pair<uLL, uLL> Puu;
#define N 300000 + 5
#define Base 19260817
#define Mod 233333333333uLL

int Case, n, A[N];
uLL ans;

inline uLL Expand(uLL x, int nxt, int op)
{
	if (op == 2)
		return x * Base + nxt;
	else return (x * Base + nxt) % Mod;
}

void Solve(int l, int r)
{
	if (l == r)
		return ;
	int mid = l + r >> 1;
	uLL h1 = 0, h2 = 0;
	int sz = 0, sz_l = 0, sz_r = 0;
	static int Stack[N];
	static uLL H1[N], H2[N];
	static Puu L[N], R[N];
	H1[0] = H2[0] = 0;
	for (int i = mid; i >= l; i --)
	{
		if (sz == 0 || Stack[sz] != A[i])
		{
			H1[sz + 1] = Expand(H1[sz], A[i], 1);
			H2[sz + 1] = Expand(H2[sz], A[i], 2);
			Stack[++ sz] = A[i];
		}
		else sz --;
		L[++ sz_l] = make_pair(H1[sz], H2[sz]);
	}
	sz = 0;
	for (int i = mid + 1; i <= r; i ++)
	{
		if (sz == 0 || Stack[sz] != A[i])
		{
			H1[sz + 1] = Expand(H1[sz], A[i], 1);
			H2[sz + 1] = Expand(H2[sz], A[i], 2);
			Stack[++ sz] = A[i];
		}
		else sz --;
		R[++ sz_r] = make_pair(H1[sz], H2[sz]);
	}
	sort(L + 1, L + sz_l + 1);
	sort(R + 1, R + sz_r + 1);
	for (int i = 1, j1 = 1, j2 = 1; i <= sz_l; i ++)
	{
		for (; j1 <= sz_r && R[j1] < L[i]; j1 ++) ;
		for (; j2 <= sz_r && R[j2] <= L[i]; j2 ++) ;
		ans += j2 - j1;
	}
	Solve(l, mid);
	Solve(mid + 1, r);
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", A + i);
		ans = 0;
		Solve(1, n);
		printf("%llu\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;
#define int long long
const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n, d, b;
int a[maxn + 5];
int sum[maxn + 5];

 main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &d, &b);
	REP(i, 0, n) scanf("%d", a + i);
	sum[0] = 0;
	REP(i, 0, n) sum[i + 1] = sum[i] + a[i];
	int ans = 0;
	REP(i, 0, n >> 1)
	{
		chkmax(ans, i + 1 - sum[min(n, i + (i + 1) * d + 1)] / b);
		chkmax(ans, i + 1 - (sum[n] - sum[max(0ll, n - i - 1 - (i + 1) * d)]) / b);
	}
	printf("%lld\n", ans);
	return 0;
}
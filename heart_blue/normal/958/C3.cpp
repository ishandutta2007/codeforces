#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
int dp[2][N];
int minv[N];
int sum[N];
int n, k, p;

class BIT
{
	int a[110];
public:
	void init()
	{
		MEM(a, 0x1f);
	}
	inline int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x, int v)
	{
		x = p - x;
		while (x < 110)
		{
			a[x] = min(a[x], v);
			x += lowbit(x);
		}
	}
	int sum(int x)
	{
		int ret = INF;
		while (x)
		{
			ret = min(ret, a[x]);
			x -= lowbit(x);
		}
		return ret;
	}
} b;
template <class T>
inline void readint(T &ret)
{
	char c;
	ret = 0;
	while ((c = getchar()) < '0' || c > '9');
	while (c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0'), c = getchar();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	readint(n);
	readint(k);
	readint(p);
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		readint(a[i]);
		a[i] %= p;
		sum[i] = sum[i - 1] + a[i];
		dp[o][i] = (a[i] + dp[o][i - 1]) % p;
	}
	for (int i = 2; i <= k; i++)
	{
		o ^= 1;
		//MEM(minv, 0x1f);
		b.init();
		MEM(dp[o], 0x1f);
		// minv[0] = sum[i - 1];
		// st.set(0, 0, sum[i - 1]);
		// st.update(1, p);
		b.add(0, sum[i - 1]);
		int tot = 0;
		for (int j = i; j <= n; j++)
		{
			tot = (tot + a[j]);
			if (tot >= p) tot -= p;
			//	st.set(0, p - tot - 1);
			dp[o][j] = min(b.sum(tot) - p, b.sum(p)) + tot;
			//dp[o][j] = min(dp[o][j], st.query(1, p) + tot + p);
			//if (tot != 0)
			//{
			//	st.set(p - tot, p - 1);
			//	dp[o][j] = min(dp[o][j], st.query(1, p) + tot);
			//}
			//for (int s = 0; s < p; s++)
			//{
			//	dp[o][j] = min(dp[o][j], minv[s] + (s + tot) % p);
			//}
			//cout << dp[o][j] << ' ';
			int t = (p - tot);
			if (t == p) t = 0;
			//minv[(p - tot) % p] = min(minv[(p - tot) % p], dp[o ^ 1][j]);
			// st.set(t, t, dp[o ^ 1][j] + t - p);
			// st.update(1, p);
			b.add(t, dp[o ^ 1][j] + t);
		}
		//cout << endl;
	}
	printf("%d\n", dp[o][n]);
	return 0;
}
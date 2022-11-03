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
const int N = 2e5 + 10;
LL a[N];
LL b[N];
int q[N];
LL dp[N];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
struct Node
{
	LL a;
	LL first;
	LL second;
};
Node solve(LL i, LL j)
{
	LL A = abs(dp[i] - dp[j]);
	LL B = abs(b[i] - b[j]);
	return Node{ A / B,A%B,B };
}
bool operator < (Node p1, Node p2)
{
	if (p1.a != p2.a) return p1.a < p2.a;
	return p1.first * p2.second < p2.first *p1.second;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int head = 0, tail = 0;
	dp[0] = 0;
	q[tail++] = 0;
	for (int i = 1; i < n; i++)
	{
		while (head + 1 < tail && solve(q[head], q[head + 1]) < Node{ a[i],0LL,1 })
			head++;
		dp[i] = dp[q[head]] + b[q[head]] * a[i];
		while (head + 1 < tail && solve(q[tail - 1], i) < solve(q[tail - 2], q[tail - 1]))
			tail--;
		q[tail++] = i;
	}
	cout << dp[n - 1] << endl;
	return 0;
}
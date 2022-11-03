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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = (1<<23) + 10;
int sum[N];
int A[30];
int lowbit(int x)
{
	return x&-x;
}
inline LL multi(int x, int y)
{
	if (INF / x < y) return INF;
	else return x*y;
}
void init(int n)
{
	sum[0] = 1;
	for (int i = 1; i < (1 << n); i++)
	{
		if (i == lowbit(i)) continue;
		int pre = i^lowbit(i);
		LL x = sum[lowbit(i)];
		sum[i] = multi(x, sum[pre]);
	}
	A[0] = 1;
	for (int i = 1; i <= n; i++) A[i] = 2 * A[i - 1];
	for (int i = 0; i <= n; i++) A[i]--;
}
int check(int a, int b, int w, int h, int cnt)
{
	int ans = 0;
	while (cnt && a > w) cnt--, ans++, w *= 2;
	while (cnt && b > h) cnt--, ans++, h *= 2;
	if (a <= w && b <= h) return ans;
	else return INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, w, h, n;
	cin >> a >> b >> w >> h >> n;
	int cnt2 = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 2) cnt2++;
		else v.push_back(x);
	}
	sort(v.rbegin(), v.rend());
	while (v.size() > 22) v.pop_back();
	n = v.size();
	int ans = min(check(a,b,w,h,cnt2),check(b,a,w,h,cnt2));
	for (int i = 0; i < v.size(); i++)
	{
		sum[1 << i] = v[i];
	}
	init(n);
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i > A[j]) continue;
			int nw = multi(sum[i], w);
			int nh = multi(sum[i^A[j]], h);
			int minv = min(check(a, b, nw, nh, cnt2),
				check(b, a, nw, nh, cnt2));
			ans = min(ans, j + minv);
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}
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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
string check(LL n)
{
	string ret;
	while (n)
	{
		ret += n % 2 + '0';
		n /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
LL getans(string s1, string s2, int f)
{
	LL n = stoll(s1, nullptr, 2);
	if (s2.back() - '0' + f > 1) return 0;
	s2.back() += f;
	LL tot = 0;
	for (int i = 0; i < s1.length() - s2.length(); i++)
	{
		tot += 1LL << i;
	}
	int flag = 0;
	for (int i = 0; i < s2.length(); i++)
	{
		if (s1[i] > s2[i])
		{
			flag = 1;
			break;
		}
		if (s1[i] < s2[i])
		{
			flag = -1;
			break;
		}
	}
	if (flag == 1)
	{
		tot += 1LL << (s1.length() - s2.length());
	}
	if (flag == 0)
	{
		LL mask = 1LL << (s1.length() - s2.length());
		mask--;
		tot += n & mask;
		tot++;
	}
	return tot;
}
LL solve1(LL n, LL k)
{
	LL ans = 1;
	LL l = 0, r = (n - 1) / 2;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		string s1 = check(n);
		string s2 = check(mid * 2 + 1);
		int m = s2.length();
		LL tot = getans(s1, s2, 0) + getans(s1, s2, 1);
		if (tot >= k) ans = mid * 2 + 1, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
LL solve2(LL n, LL k)
{
	LL ans = 1;
	LL l = 1, r = n / 2;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		string s1 = check(n);
		string s2 = check(mid * 2);
		int m = s2.length();
		LL tot = getans(s1, s2, 0) + getans(s1, s2, 1);
		if (tot >= k) ans = mid * 2, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	cin >> n >> k;

	printf("%lld\n", max(solve1(n, k), solve2(n, k)));
	return 0;
}
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
const int N = 1e6 + 10;
pair<int, int> p[N];
LL solve(int n)
{
	set<int> s;
	s.insert(0);
	s.insert(n + 1);
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, pos;
		tie(x, pos) = p[i];
		auto iter = s.lower_bound(pos);
		int r = *iter;
		int l = *(--iter);
		s.insert(pos);
		ret += 1LL * x*(pos - l)*(r - pos);
	}
	return ret;
}
inline int readint() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9')c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	n = readint();

	for (int i = 1; i <= n; i++)
	{
		p[i].first = readint();
		p[i].second = i;
	}
	LL ans = 0;
	sort(p + 1, p + n + 1);
	ans -= solve(n);
	reverse(p + 1, p + n + 1);
	ans += solve(n);
	printf("%lld\n", ans);
	return 0;
}
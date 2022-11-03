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
LL s[N];
class BIT
{
public:
	LL a[N];
	inline int lowbit(int x)
	{
		return x&-x;
	}
	void init()
	{
		MEM(a, 0);
	}
	void add(int x, LL val)
	{
		LL ret = sum(x - 1) + val;
		while (x < N)
		{
			a[x] = max(ret, a[x]);
			x += lowbit(x);
		}
	}
	LL sum(int x)
	{
		LL ret = 0;
		while (x)
		{
			ret = max(ret, a[x]);
			x -= lowbit(x);
		}
		return ret;
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<LL> v;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		LL r, h;
		cin >> r >> h;
		s[i] = r*r*h;
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++)
	{
		int o = lower_bound(v.begin(), v.end(), s[i]) - v.begin() + 1;
		b.add(o, s[i]);
	}
	printf("%.15f\n", b.sum(N - 1)*acos(0.0) * 2);
	return 0;
}
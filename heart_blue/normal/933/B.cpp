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
const int N = 2e3 + 10;
vector<LL> ans;
vector<LL> v;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL p;
	int k;
	cin >> p >> k;
	if (p < k)
	{
		cout << 1 << endl;
		cout << p << endl;
		return 0;
	}
	ans.push_back(p%k);
	v.push_back(-(p / k));
	ans.push_back(-(p / k));
	map<LL, int> mc;
	while (ans.back() <= 0 || ans.back() >= k)
	{
		LL x = v.back();
		if (mc.count(x))
		{
			cout << -1 << endl;
			return 0;
		}
		mc[x] = 1;
		if (x < 0)
		{
			LL o = (abs(x) - 1) / k + 1;
			v.push_back(o);
			ans.back() += o * k;
			ans.push_back(o);
		}
		else
		{
			LL o = x / k;
			v.push_back(-o);
			ans.back() %= k;
			ans.push_back(-o);
		}
	}
	printf("%d\n", ans.size());
	for (auto &x : ans) printf("%lld ", x);
	return 0;
}
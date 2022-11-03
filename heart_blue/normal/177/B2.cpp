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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i * i <= n; i++)
	{
		if (n%i) continue;
		v.push_back(i);
		v.push_back(n / i);
	}
	sort(v.begin(), v.end());
	map<int, int> ans;
	for (auto &x : v)
	{
		int tmp = 0;
		for (auto &y : v)
		{
			if (y == 1) continue;
			if (x%y) continue;
			tmp = max(tmp, ans[x / y]);
		}
		ans[x] = x + tmp;
	}
	cout << ans[n] << endl;
	return 0;
}
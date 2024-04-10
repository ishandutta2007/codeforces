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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> ans;
	if (k >= n)
	{
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	for (int i = k + 1; i <= 2 * k + 1; i++)
	{
		if ((n - i) % (2 * k + 1)) continue;
		for (int j = i - k; j <= n; j += 2 * k + 1)
		{
			ans.push_back(j);
		}
	}
	for (int i = k + 1; i <= 2 * k + 1; i++)
	{
		for (int j = i; j <= 2 * k + 1; j++)
		{
			if (i + j > n) break;
			if ((n - i - j) % (2 * k + 1)) continue;
			int l = i, r = n - j + 1;
			if (!ans.empty() && 2 + (n - i - j) / (2 * k + 1) >= ans.size()) continue;
			ans.clear();
			for (int i = l - k; i < r; i += 2 * k + 1) ans.push_back(i);
			ans.push_back(r + k);
		}
	}
	cout << ans.size() << endl;
	for (auto& x : ans) cout << x << ' ';
	return 0;
}
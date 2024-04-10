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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> ans;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int o = 1 << 30;
	while (o)
	{
		ans.clear();
		LL cur = (1LL << 31) - 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] & o)
			{
				cur &= a[i];
				ans.push_back(a[i]);
			}
		}
		if (cur%o == 0 && !ans.empty())
		{
			cout << ans.size() << endl;
			for (auto &x : ans) cout << x << ' ';
			return 0;
		}
		o >>= 1;
	}
	return 0;
}
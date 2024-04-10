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
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int sz;
		cin >> sz;
		v[i].resize(sz);
		for (auto& x : v[i])
			cin >> x;
		sort(v[i].begin(), v[i].end());
	}
	int l = n, r = 2;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j + 1 < v[i].size(); j++)
		{
			int x = v[i][j], y = v[i][j + 1];
			if (upper_bound(v[l].begin(), v[l].end(), y) - lower_bound(v[l].begin(), v[l].end(), x) !=
				upper_bound(v[r].begin(), v[r].end(), y) - lower_bound(v[r].begin(), v[r].end(), x))
				ans++;
		}
		l++, r++;
		if (l > n) l -= n;
		if (r > n) r -= n;
	}
	cout << ans << endl;
	return 0;
}
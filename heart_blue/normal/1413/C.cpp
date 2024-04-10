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
int a[7];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 6; i++) cin >> a[i];
	set<pair<int, int>> s;
	int ans = INF;
	sort(a + 1, a + 7);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 6; j > 0; j--)
		{
			v[i].push_back(x - a[j]);
		}
		s.emplace(v[i].back(), i);
	}
	while (1)
	{
		ans = min(ans, s.rbegin()->first - s.begin()->first);
		int pos = s.rbegin()->second;
		s.erase(*s.rbegin());
		v[pos].pop_back();
		if (v[pos].empty()) break;
		s.emplace(v[pos].back(), pos);
	}
	printf("%d\n", ans);
	return 0;
}
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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while (v.size() < a[i])
		{
			v.push_back(i);
		}
		while (v.size() > a[i])
		{
			ans.emplace_back(v.back(), i - 1);
			v.pop_back();
		}
	}
	while (!v.empty())
	{
		ans.emplace_back(v.back(), n);
		v.pop_back();
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}
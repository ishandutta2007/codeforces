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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j <= n; j += i) a[j] = 1;
	}
	vector<pair<int, int>> ans;
	for (int i = n; i >= 2; i--)
	{
		if (a[i]) continue;
		a[i] = 1;
		vector<int> v;
		for (int j = i; j <= n; j += i)
		{
			if (a[j] == 0) continue;
			v.push_back(j);
			a[j] = 0;
		}
		if (v.size() == 1) continue;
		if (v.size() & 1) v.erase(v.begin() + 1), a[i * 2] = 1;
		for (int j = 0; j + 1 < v.size(); j += 2)
		{
			ans.emplace_back(v[j], v[j + 1]);
		}
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}
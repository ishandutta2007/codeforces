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
const int N = 4e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cout << "? 1" << endl;
	vector<pair<int, int>> ans;
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
		if (x == 1)
			ans.emplace_back(1, i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i & 1)
			for (auto& x : v[i])
				v1.push_back(x);
		else
			for (auto& x : v[i])
				v2.push_back(x);
	}
	if (v1.size() > v2.size())
		swap(v1, v2);
	for (auto& x : v1)
	{
		cout << "? " << x << endl;
		for (int i = 1; i <= n; i++)
		{
			int d;
			cin >> d;
			if (d == 1)
			{
				ans.emplace_back(i, x);
			}
		}
	}
	for (auto& [x, y] : ans)
	{
		if (x > y)
			swap(x, y);
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	cout << "!" << '\n';
	for (auto [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	cout.flush();
	return 0;
}
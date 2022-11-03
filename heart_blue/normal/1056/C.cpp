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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int p[N];
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> p[i];
		vp.emplace_back(p[i], i);
	}
	sort(vp.rbegin(), vp.rend());
	vector<int> v;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x] = y;
		a[y] = x;
		if (p[x] > p[y]) v.push_back(x);
		else v.push_back(y);
	}
	int o;
	cin >> o;
	auto iter = vp.begin();
	int pre = 0;
	while (iter != vp.end())
	{
		if (o == 1)
		{
			if (flag[iter->second])
			{
				iter++;
				continue;
			}
			if (a[pre] && flag[a[pre]] == 0)
			{
				cout << a[pre] << endl;
				flag[a[pre]] = 1;
			}
			else
			{
				while (!v.empty() && flag[v.back()]) v.pop_back();
				if (!v.empty())
				{
					cout << v.back() << endl;
					flag[v.back()] = 1;
					v.pop_back();
				}
				else
				{
					flag[iter->second] = 1;
					cout << iter->second << endl;
				}
			}
		}
		else
		{
			int x;
			cin >> x;
			pre = x;
			flag[x] = 1;
		}
		o = 3 - o;
	}
	return 0;
}
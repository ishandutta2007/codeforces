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
const int INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> vp[N];
int maxv[N];
set<pair<int, int>> s;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(maxv, 0);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		maxv[x] = y;
		vp[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (maxv[i] > 0)
		{
			s.insert({ -maxv[i],i });
		}
	}
	int k;
	cin >> k;
	while (k--)
	{
		int m;
		cin >> m;
		vector<int> v(m);
		for (auto &x : v)
		{
			cin >> x;
			if (maxv[x]) s.erase({ -maxv[x],x });
		}
		if (s.size() == 0)
		{
			cout << "0 0\n";
		}
		else if (s.size() == 1)
		{
			int x = s.begin()->second;
			cout << x << ' ' << vp[x][0] << '\n';
		}
		else
		{
			int x = s.begin()->second;
			s.erase(s.begin());
			int y = s.begin()->second;
			cout << x << ' ' << *lower_bound(vp[x].begin(), vp[x].end(), vp[y].back()) << '\n';
			s.insert({ -maxv[x],x });
		}
		for (auto &x : v) if (maxv[x]) s.insert({ -maxv[x],x });
	}
	return 0;
}
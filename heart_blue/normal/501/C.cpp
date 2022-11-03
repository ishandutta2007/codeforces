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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = (1 << 16) + 10;
int deg[N];
int sum[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> vp;
	list<int> l;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> deg[i] >> sum[i];
		if (deg[i] == 1)
		{
			l.push_back(i);
		}
	}
	while (!l.empty())
	{
		int x = l.front();
		l.pop_front();
		if (deg[x] == 0) continue;
		int y = sum[x];
		vp.push_back({ x, y });
		deg[x]--;
		deg[y]--;
		sum[y] ^= x;
		if (deg[y] == 1)
		{
			l.push_back(y);
		}
	}
	for (auto &p : vp)
	{
		if (p.first > p.second) swap(p.first, p.second);
	}
	if (!vp.empty())
	{
		sort(vp.begin(), vp.end());
		vp.resize(unique(vp.begin(), vp.end()) - vp.begin());
	}
	cout << vp.size() << '\n';
	for (auto &p : vp)
	{
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}
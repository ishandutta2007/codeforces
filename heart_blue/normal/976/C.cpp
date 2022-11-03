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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> vp(n);
	for (int i = 0; i < n; i++)
	{
		auto &p = vp[i].first;
		cin >> p.first >> p.second;
		p.second = -p.second;
		vp[i].second = i + 1;
	}
	sort(vp.begin(), vp.end());
	int maxv = -1;
	int key = -1;
	for (int i = 0; i < n; i++)
	{
		auto &p = vp[i].first;
		p.second = -p.second;
		if (p.second <= maxv)
		{
			cout << vp[i].second << ' ' << key << endl;
			return 0;
		}
		if (maxv < p.second)
		{
			maxv = p.second;
			key = vp[i].second;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}
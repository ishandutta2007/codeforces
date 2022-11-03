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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	map<LL, LL> m;
	m[a] = -1;
	list<LL> l;
	l.push_back(a);
	while (!l.empty())
	{
		LL x = l.front(); l.pop_front();
		if (x > b) continue;
		if (x == b) break;
		if (!m.count(x * 2)) m[x * 2] = x, l.push_back(x * 2);
		if (!m.count(x * 10 + 1)) m[x * 10 + 1] = x, l.push_back(x * 10 + 1);
	}
	if (m.count(b))
	{
		vector<int> ans;
		int x = b;
		while (x != -1)
		{
			ans.push_back(x);
			x = m[x];
		}
		cout << "YES" << endl;
		cout << ans.size() << endl;
		reverse(ans.begin(), ans.end());
		for (auto &x : ans) cout << x << ' ';
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
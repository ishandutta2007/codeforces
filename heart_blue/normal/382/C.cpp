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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	if (n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	int o = v[1] - v[0];
	if (v.back() - v.front() == 0)
	{
		cout << 1 << endl;
		cout << v.front() << endl;
		return 0;
	}
	if (n == 2)
	{
		if (v[0] == v[1])
		{
			cout << 1 << endl;
			cout << v[0] << endl;
		}
		else if ((v[1] - v[0]) % 2 == 0)
		{
			cout << 3 << endl;
			cout << v[0] - o << ' ' << v[0] + o / 2 << ' ' << v[1] + o << endl;
		}
		else
		{
			cout << 2 << endl;
			cout << v[0] - o << ' ' << v[1] + o << endl;
		}
		return 0;
	}
	map<int, int> m;
	for (int i = 1; i < n; i++) m[v[i] - v[i - 1]]++;
	if (m.size() == 1)
	{
		cout << 2 << endl;
		cout << v[0] - o << ' ' << v[n - 1] + o << endl;
		return 0;
	}
	if (m.size() > 2)
	{
		cout << 0 << endl;
		return 0;
	}
	if (m[o] == 1)
	{
		if (o % 2 == 0 && m.count(o / 2) && o != 0)
		{
			cout << 1 << endl << v[0] + o / 2 << endl;
			return 0;
		}
	}
	if (m[o * 2] == 1 && o != 0)
	{
		cout << 1 << endl;
		for (int i = 1; i < n; i++)
		{
			if (v[i] - v[i - 1] == o * 2)
			{
				cout << v[i] - o << endl;
				break;
			}
		}
		return 0;
	}
	cout << 0 << endl;
	return 0;
}
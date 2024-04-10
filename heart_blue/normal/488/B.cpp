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
bool check(vector<int> v, int x = 0, int y = 0)
{
	if (x) v.push_back(x);
	if (y) v.push_back(y);
	sort(v.begin(), v.end());
	int q1 = (v[0] + v[1] + v[2] + v[3]);
	int q2 = (v[1] + v[2]) * 2;
	int q3 = (v[3] - v[0]) * 4;
	if (q1 == q2 && q2 == q3)
	{
		cout << "YES" << endl;
		if (x) cout << x << endl;
		if (y) cout << y << endl;
		return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	if (n == 0)
	{
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << endl;
		cout << 3 << endl;
		cout << 3 << endl;
		return 0;
	}
	if (n == 1)
	{
		cin >> v[0];
		int x = v[0];
		cout << "YES" << endl;
		cout << x << endl;
		cout << 3 * x << endl;
		cout << 3 * x << endl;
		return 0;
	}
	if (n == 4)
	{
		if (!check(v)) cout << "NO" << endl;
		return 0;
	}
	if (n == 2)
	{
		for (int i = 1; i <= 2000; i++)
		{
			for (int j = i; j <= 2000; j++)
			{
				if (check(v, i, j)) return 0;
			}
		}
		cout << "NO" << endl;
		return 0;
	}
	if (n == 3)
	{
		for (int i = 1; i <= 2000; i++)
		{
			if (check(v, i)) return 0;
		}
		cout << "NO" << endl;
		return 0;
	}

	return 0;
}
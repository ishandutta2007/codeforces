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
const int N = 1e3 + 10;
int a[N][N];
bool check(int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		if (x - i < 1) break;
		for (int j = 0; j < 3; j++)
		{
			if (y - j < 1) break;
			if (a[x - i][y - j]++ == 8) return true;
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	vector<pair<int, int>> vp;
	int a, b;
	cin >> n >> d;
	cin >> a >> b;
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp.push_back({ x*a + y*b,i });
		tot += x*a + y*b;
	}
	sort(vp.begin(), vp.end());
	while (tot > d)
	{
		tot -= vp.back().first;
		vp.pop_back();
	}
	cout << vp.size() << endl;
	for (auto &p : vp) cout << p.second << ' ';
	return 0;
}
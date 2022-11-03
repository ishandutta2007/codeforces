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
const int N = 1e5 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<pair<int, int>, int> mp;
	vector<int> x, y;
	int n;
	cin >> n;
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int px = x[i] - x[j];
			int py = y[i] - y[j];
			if (px == 0 || py == 0) px = abs(px), py = abs(py);
			if (px < 0) px = -px, py = -py;
			mp[{px, py}]++;
		}
	}
	LL ans = 0;
	for (auto p : mp)
	{
		ans += (LL)p.second *(p.second - 1) / 2;
	}
	cout << ans / 2<< endl;
	return 0;
}
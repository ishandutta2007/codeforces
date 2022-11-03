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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v[2];
	int m, n;
	cin >> n >> m;
	int t;
	for (t = 1; t <= min(2 * n, m); t++) v[0].push_back(t);
	for (;t <= m;t++) v[1].push_back(t);
	int o = 0;
	if (!v[0].empty()) reverse(v[0].begin(), v[0].end());
	if (!v[1].empty()) reverse(v[1].begin(), v[1].end());
	while (!(v[0].empty() && v[1].empty()))
	{
		o ^= 1;
		if (v[o].empty()) continue;
		cout << v[o].back() << ' ';
		v[o].pop_back();
	}
	return 0;
}
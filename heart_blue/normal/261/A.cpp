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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int n, m;
	cin >> m;
	int minv = INF;
	while (m--)
	{
		int x;
		cin >> x;
		minv = min(minv, x);
	}
	cin >> n;
	v.resize(n);
	for (auto &x : v) cin >> x;
	sort(v.rbegin(), v.rend());
	LL ans = 0;
	for (int i = 0; i < n; i += minv + 2)
	{
		for (int k = i; k < min(n, i + minv); k++)
		{
			ans += v[k];
		}
	}
	cout << ans << endl;
	return 0;
}
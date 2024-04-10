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
#include <random>
#include <cassert>
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = INF;
	for (auto& x : b)
	{
		int delta = (x - a[0]) % m;
		if (delta < 0) delta += m;
		vector<int> v;
		for (auto& y : a) v.push_back((y + delta) % m);
		sort(v.begin(), v.end());
		if (v == b)
		{
			ans = min(ans, delta);
		}
	}
	cout << ans << endl;
	return 0;
}
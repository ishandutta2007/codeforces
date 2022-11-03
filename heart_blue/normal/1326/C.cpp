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
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.emplace_back(x, i);
	}
	sort(vp.rbegin(), vp.rend());
	vector<int> v;
	LL sum = 0;
	for (int i = 0; i < k; i++)
	{
		v.push_back(vp[i].second);
		sum += vp[i].first;
	}
	sort(v.begin(), v.end());
	LL mod = 998244353;
	LL ans = 1;
	for (int i = 1; i < v.size(); i++)
	{
		ans = ans * (v[i] - v[i - 1]) % mod;
	}
	cout << sum << ' ' << ans << endl;
	return 0;
}
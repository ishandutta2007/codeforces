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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	v.push_back(v.front() * 2);
	int g = v.front();
	for (auto &x : v) g = gcd(x, g);
	cout << "YES" << endl;
	if (g != 1)
	{
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	int cnt = 0;
	for (auto &x : v)
	{
		if (x & 1) cnt++;
		else ans += (cnt / 2) + (cnt & 1) * 2, cnt = 0;
	}
	cout << ans << endl;
	return 0;
}
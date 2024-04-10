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
	vector<int> v1(n);
	vector<int> v2(m);
	for (auto &x : v1) cin >> x;
	for (auto &y : v2) cin >> y;
	reverse(v2.begin(), v2.end());
	int ans = 0;
	for (auto &x : v1)
	{
		if (v2.empty()) break;
		if (x <= v2.back())
		{
			v2.pop_back();
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
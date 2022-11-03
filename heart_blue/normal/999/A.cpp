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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &x : v)
	{
		cin >> x;
	}
	int ans = 0;
	for (auto &x : v)
	{
		if (x <= k) ans++;
		else break;
	}
	reverse(v.begin(), v.end());
	for (auto &x : v)
	{
		if (x <= k) ans++;
		else break;
	}
	cout << min(ans, n) << endl;
	return 0;
}
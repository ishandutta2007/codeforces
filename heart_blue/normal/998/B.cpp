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
const int N = 2e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i > 1 && o == 0) v.push_back(abs(a[i] - a[i - 1]));
		if (a[i]&1) o++;
		else o--;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto &x : v)
	{
		if (k >= x) k -= x, ans++;
	}
	cout << ans << endl;
	return 0;
}
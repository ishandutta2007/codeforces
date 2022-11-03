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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, a;
	cin >> n >> k >> a;
	int m;
	cin >> m;
	vector<int> v(m);
	for (auto &x : v) cin >> x;
	int ans = -1;
	int l = 1, r = m;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		vector<int> v1;
		for (int i = 0; i < mid; i++) v1.push_back(v[i]);
		v1.push_back(n + 1);
		sort(v1.begin(), v1.end());
		int tot = 0;
		int pre = 0;
		for (auto &x : v1)
		{
			tot += (x - pre) / (a + 1);
			pre = x;
		}
		if (tot < k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
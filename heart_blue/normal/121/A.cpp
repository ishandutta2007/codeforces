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
const int N = 2e2 + 10;
vector<LL> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	v.push_back(4);
	v.push_back(7);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > INF) continue;
		v.push_back(v[i] * 10 + 4);
		v.push_back(v[i] * 10 + 7);
	}
	sort(v.begin(), v.end());
	LL l, r;
	cin >> l >> r;
	LL ans = 0;
	while (l <= r)
	{
		int o = lower_bound(v.begin(), v.end(), l) - v.begin();
		LL x = v[o];
		ans += (min(r, x) - l + 1)*x;
		l = x + 1;
	}
	cout << ans << endl;
	return 0;
}
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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	scanf("%d%d", &n, &d);
	vector<int> v(n);
	int ans = 0;
	for (auto& x : v)
		scanf("%d", &x);
	sort(v.rbegin(), v.rend());
	d++;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] * 1LL * (v.size() - i) < d) break;
		ans++;
		int cnt = (d + v[i] - 1) / v[i];
		while (--cnt) v.pop_back();
	}
	printf("%d\n", ans);
	return 0;
}
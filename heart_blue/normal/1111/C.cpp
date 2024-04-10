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
vector<int> v;
int A, B;
LL dfs(int l, int r)
{
	int tot = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
	if (tot == 0) return A;
	LL ret = 1LL * B * tot * (r - l + 1);
	if (l == r) return ret;
	int mid = (l + r) / 2;
	ret = min(ret, dfs(l, mid) + dfs(mid + 1, r));
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k >> A >> B;
	v.resize(k);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());
	cout << dfs(1, 1 << n) << endl;
	return 0;
}
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
LL a[N];
LL b[N];
vector<LL> v;
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], v.push_back(a[i]);
	for (int j = 1; j <= m; j++) cin >> b[j], v.push_back(b[j]);
	sort(v.begin(), v.end());
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	reverse(b + 1, b + 1 + m);
	MEM(ans, 0);
	int p = 1;
	LL sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		while (p <= n && a[p] <= v[i])
		{
			sum += a[p++];
		}
		ans[i] += v[i] * (p - 1) - sum;
	}
	p = 1;
	sum = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		while (p <= m && b[p] >= v[i])
		{
			sum += b[p++];
		}
		ans[i] += sum - v[i] * (p - 1);
	}
	LL res = INF*INF;
	for (int i = 0; i < v.size(); i++) res = min(res, ans[i]);
	cout << res << endl;
	return 0;
}
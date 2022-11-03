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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	vector<int> ans;
	for (int i = 0; i < m; i++) v[i] = i + 1;
	sort(v.begin(), v.end(), [](int x, int y) -> bool
	{
		return (x&-x) > (y&-y);
	});
	for (auto &x : v)
	{
		if ((x&-x) <= n)
		{
			ans.push_back(x);
			n -= (x&-x);
		}
	}
	if (n != 0) cout << -1 << endl;
	else
	{
		cout << ans.size() << endl;
		for (auto &x : ans)
		{
			cout << x << ' ';
		}
		cout << endl;
	}
	return 0;
}
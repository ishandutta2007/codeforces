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
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.push_back({ x,i });
	}
	sort(vp.rbegin(), vp.rend());
	LL ans = 0;
	for (int i = 0; i < m * k; i++)
	{
		int x, pos;
		tie(x, pos) = vp[i];
		ans += x;
		flag[pos] = 1;
	}
	vector<int> v;
	int key = m;
	for (int i = 1; i <= n; i++)
	{
		flag[i] += flag[i - 1];
		if (flag[i] == key)
		{
			v.push_back(i);
			key += m;
		}
	}
	v.pop_back();
	cout << ans << endl;
	for (auto& x : v) cout << x << ' ';
	return 0;
}
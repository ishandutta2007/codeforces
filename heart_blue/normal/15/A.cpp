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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a;
	vector<pair<int, int>> vp;
	cin >> n >> a;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		vp.push_back({ x * 2 - y, x * 2 + y });
	}
	int ans = 2;
	sort(vp.begin(), vp.end());
	for (int i = 1; i < vp.size(); i++)
	{
		if (vp[i].first - vp[i - 1].second > 2 * a) ans += 2;
		if (vp[i].first - vp[i - 1].second == 2 * a) ans++;
	}
	cout << ans << endl;
	return 0;
}
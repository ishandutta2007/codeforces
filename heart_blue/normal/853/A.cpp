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
const int N = 1e6 + 10;
int res[N];
set<int> s;
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) s.insert(i + k);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.push_back({ x,i });
	}
	sort(vp.rbegin(), vp.rend());
	LL ans = 0;
	for (auto &p : vp)
	{
		int x, o;
		tie(x, o) = p;
		int pos = *s.lower_bound(o);
		s.erase(pos);
		ans += LL(pos - o)*x;
		res[o] = pos;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	return 0;
}
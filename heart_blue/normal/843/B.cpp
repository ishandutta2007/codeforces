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
const int N = 4e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, start, x;
	cin >> n >> start >> x;
	vector<int> v;
	for (int i = 1; i <= n; i++) v.push_back(i);
	int lval = -1;
	random_shuffle(v.rbegin(), v.rend());
	int ans = INF;
	int cnt = 1999;
	for (auto &o : v)
	{
		if (flag[o]) continue;
		if (cnt <= 1000) break;
		cnt--;
		cout << "? " << o << endl;
		int val, nex;
		cin >> val >> nex;
		flag[o] = 1;
		if(nex != -1) flag[nex] = 1;
		if (val >= x) ans = min(ans, val);
		else if (lval < val)
		{
			lval = val;
			start = nex;
		}
	}
	while (cnt--)
	{
		if (start == -1) break;
		cout << "? " << start << endl;
		int val, nex;
		cin >> val >> nex;
		if (val >= x)
		{
			ans = min(ans, val);
			break;
		}
		start = nex;
	}
	if (ans == INF) ans = -1;
	cout << "! " << ans << endl;
	return 0;
}
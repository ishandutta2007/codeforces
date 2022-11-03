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
const int N = 1e3 + 10;
int vis[N];
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int,int>> ans;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.push_back({ x,i });
	}
	vis[0] = 1;
	sort(vp.rbegin(), vp.rend() - 1);
	for (int i = 0; i < n; i++)
	{
		if (!vis[i]) break;
		int cnt = vp[i].first;
		for (int j = i + 1; j < n; j++)
		{
			if (vis[j]) continue;
			if (cnt == 0) break;
			ans.push_back({ vp[i].second,vp[j].second });
			cnt--;
			vis[j] = 1;
		}
	}
	if (ans.size() != n - 1) puts("-1");
	else
	{
		cout << ans.size() << endl;
		for (auto &p : ans) cout << p.first << ' ' << p.second << endl;
	}
	return 0;
}
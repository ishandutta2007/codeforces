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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc1, mc2;
	int ans = 0;
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) cin >> a[i], mc2[a[i]] = 0;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		mc2[x]++;
	}
	int zero = 0;
	for (auto &p : mc2) if (p.second == 0) zero++;
	vector<int> v;
	for (int o = 1; o <= p; o++)
	{
		int cnt = zero;
		mc1.clear();
		for (int i = 0; o + i*p <= n; i++)
		{
			int s = o + i*p;
			if (mc1[a[s]] == mc2[a[s]]) cnt--;
			mc1[a[s]]++;
			if (mc1[a[s]] == mc2[a[s]]) cnt++;
			if (i >= m)
			{
				int t = o + (i - m)*p;
				if (mc1[a[t]] == mc2[a[t]]) cnt--;
				mc1[a[t]]--;
				if (mc1[a[t]] == mc2[a[t]]) cnt++;
			}
			if (cnt == mc2.size()) ans++, v.push_back(o + (i - m + 1)*p);
		}
	}
	cout << ans << endl;
	sort(v.begin(), v.end());
	for (auto &x : v) cout << x << ' ';
	return 0;
}
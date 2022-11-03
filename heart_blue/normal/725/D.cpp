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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<LL, LL>> vp;
	priority_queue<LL, vector<LL>, greater<LL>> pq;
	LL tot, dumb;
	cin >> tot >> dumb;
	for (int i = 1; i < n; i++)
	{
		LL t, w;
		cin >> t >> w;
		if (t > tot) pq.push(w - t + 1);
		else vp.push_back({ t,w });
	}
	sort(vp.begin(), vp.end());
	int ans = pq.size();
	while (!pq.empty())
	{
		ans = min(ans, (int)pq.size());
		if (pq.top() > tot) break;
		tot -= pq.top();
		pq.pop();
		while (!vp.empty() && vp.back().first > tot)
		{
			pq.push(vp.back().second - vp.back().first + 1);
			vp.pop_back();
		}
	}
	ans = min(ans, (int)pq.size());
	cout << ans + 1 << endl;
	return 0;
}
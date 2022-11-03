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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> vp(n);
	for (auto& p : vp) cin >> p.second >> p.first;
	sort(vp.rbegin(), vp.rend());
	LL ans = 0;
	LL sum = 0;
	for (auto& p : vp)
	{
		pq.push(p.second);
		sum += p.second;
		while (pq.size() > k)
		{
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans, sum * p.first);
	}
	cout << ans << endl;
	return 0;
}
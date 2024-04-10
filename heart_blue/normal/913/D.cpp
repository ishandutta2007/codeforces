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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<tuple<int, int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		int a, x;
		cin >> a >> x;
		vp.push_back({ a,x,i+1 });
	}
	sort(vp.begin(), vp.end());
	priority_queue<pair<int,int>> pq;
	LL tot = 0;
	int ans = 0;
	for (int i = n; i > 0; i--)
	{
		int a, x, pos;
		tie(a, x, pos) = vp[i - 1];
		tot += x;
		pq.push({ x,pos });
		while (!pq.empty())
		{
			if (tot > t)
			{
				tot -= pq.top().first;
				pq.pop();
				continue;
			}
			if (pq.size() > a)
			{
				tot -= pq.top().first;
				pq.pop();
				continue;
			}
			break;
		}
		ans = max(ans, (int)pq.size());
	}
	while (!pq.empty()) pq.pop();
	tot = 0;
	for (int i = n; i > 0; i--)
	{
		int a, x, pos;
		tie(a, x, pos) = vp[i - 1];
		tot += x;
		pq.push({ x,pos });
		while (!pq.empty())
		{
			if (tot > t)
			{
				tot -= pq.top().first;
				pq.pop();
				continue;
			}
			if (pq.size() > a)
			{
				tot -= pq.top().first;
				pq.pop();
				continue;
			}
			break;
		}
		if (pq.size() == ans)
		{
			cout << ans << endl;
			cout << ans << endl;
			while (!pq.empty())
			{
				cout << pq.top().second << ' ';
				pq.pop();
			}
			return 0;
		}
	}
	return 0;
}
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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL ans[N];
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(ans, 0x3f);
	int n, p;
	scanf("%d%d", &n, &p);
	vector<pair<LL, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		vp.emplace_back(x, i);
	}
	sort(vp.begin(), vp.end());
	vp.emplace_back(INF * INF, n + 1);
	deque<int> q;
	set<int> inq;
	set<int> s;
	LL qtime = 0;
	LL stime = 0;
	LL cur = 0;
	for (auto& pp : vp)
	{
		LL x;
		int pos;
		tie(x, pos) = pp;
		while (1)
		{
			if (q.empty() && s.empty()) break;
			if (q.empty())
			{
				q.push_back(*s.begin());
				inq.insert(*s.begin());
				ans[*s.begin()] = max(cur, a[*s.begin()]) + p;
				s.erase(*s.begin());
			}
			else if (ans[q.front()] < x)
			{
				cur = ans[q.front()];
				LL res = ans[q.front()];
				inq.erase(q.front());
				q.pop_front();
				if (!q.empty())
					ans[q.front()] = res + p;
				if (q.empty() && !s.empty())
				{
					q.push_back(*s.begin());
					inq.insert(*s.begin());
					ans[*s.begin()] = max(cur, a[*s.begin()]) + p;
					s.erase(s.begin());
				}
				if (!q.empty() && !s.empty() && *s.begin() < *inq.begin())
				{
					q.push_back(*s.begin());
					inq.insert(*s.begin());
					s.erase(s.begin());
				}
			}
			else break;
		}
		cur = x;
		s.insert(pos);
		if (q.empty())
		{
			q.push_back(*s.begin());
			inq.insert(*s.begin());
			ans[*s.begin()] = max(cur, a[*s.begin()]) + p;
			s.erase(s.begin());

		}
		else if (*s.begin() < *inq.begin())
		{
			q.push_back(*s.begin());
			inq.insert(*s.begin());
			s.erase(s.begin());
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%lld%c", ans[i], " \n"[i == n]);
	return 0;
}
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
const int N = 3e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		b[x] = i;
	}
	for (int i = 1; i <= n; i++) a[i] = b[a[i]];
	map<int, int> mc;
	int ans = 0;
	deque<int> q;
	for (int i = 1; i <= n; i++) q.push_back(a[i]);
	int cur = 0;
	while (!q.empty())
	{
		while (1)
		{
			if (!q.empty())
			{
				if (cur + 1 == q.front())
				{
					q.pop_front();
					cur++;
					continue;
				}
			}
			if (!mc.empty())
			{
				if (mc.begin()->first == cur + 1)
				{
					cur++;
					mc.erase(cur);
					continue;
				}
			}
			break;
		}
		if (!q.empty())
		{
			mc[q.back()] = 1;
			q.pop_back();
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
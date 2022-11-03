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
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL ans[N];
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, b;
	cin >> n >> b;
	vector<pair<LL, LL>> vp;
	LL t, d;
	queue<pair<int, pair<LL, LL>>> qp;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> d;
		vp.push_back({ t,d });
	}
	int curIndex = 0;
	LL curTime = 0;
	while (1)
	{
		if (!qp.empty())
		{
			auto tmp = qp.front();
			qp.pop();
			curTime = max(curTime, tmp.second.first) + tmp.second.second;
			ans[tmp.first] = curTime;
		}
		
		while (curIndex < n && vp[curIndex].first < curTime)
		{
			if (qp.size() >= b)
			{
				ans[curIndex] = -1;
			}
			else
			{
				qp.push({ curIndex, vp[curIndex] });
			}
			curIndex++;
		}
		if (qp.empty())
		{
			if (curIndex == n) break;
			qp.push({ curIndex, vp[curIndex] });
			curIndex++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
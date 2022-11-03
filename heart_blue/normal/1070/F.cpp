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
const int N = 4e5 + 10;

vector<int> v[5];
int pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq2;
	priority_queue<int> pq1;
	int tot = 0;
	while (n--)
	{
		string str;
		int val;
		cin >> str >> val;
		int o = (str[0] - '0') * 2 + str[1] - '0';
		if (o == 3) cnt++, sum += val;
		else if (o == 0) pq1.push(val);
		else v[o].push_back(val);
	}
	int maxv = min(v[1].size(), v[2].size());
	sort(v[1].rbegin(), v[1].rend());
	sort(v[2].rbegin(), v[2].rend());
	for (int i = 0; i < maxv; i++)
	{
		pre[i + 1] += pre[i] + v[1][i] + v[2][i];
	}
	while (v[1].size() > maxv)
	{
		pq1.push(v[1].back());
		v[1].pop_back();
	}
	while (v[2].size() > maxv)
	{
		pq1.push(v[2].back());
		v[2].pop_back();
	}
	int ans = sum;
	for (int i = v[1].size(); i >= 0; i--)
	{
		int rest = 2 * (i + cnt) - (cnt + 2 * i);
		if (rest >= 0)
		{
			while (!pq1.empty() && pq2.size() < rest)
			{
				tot += pq1.top();
				pq2.push(pq1.top());
				pq1.pop();
			}
			while (pq2.size() > rest)
			{
				tot -= pq2.top();
				pq1.push(pq2.top());
				pq2.pop();
			}
			while (!pq1.empty() && !pq2.empty())
			{
				if (pq1.top() > pq2.top())
				{
					int x = pq1.top();
					int y = pq2.top();
					pq1.pop();
					pq2.pop();
					pq1.push(y);
					pq2.push(x);
					tot += x - y;
				}
				else break;
			}
			ans = max(ans, sum + tot + pre[i]);
		}
		if (i > 0)
		{
			pq1.push(v[1].back());
			pq2.push(v[2].back());
			v[1].pop_back();
			v[2].pop_back();
		}
	}
	cout << ans << endl;
	return 0;
}
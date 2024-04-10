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
const int N = 5e3 + 10;
int a[N];
int flag[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
			pq.push(i);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		while (a[i] != 0)
		{
			int x = pq.top();
			pq.pop();
			ans.push_back(x);
			flag[x] = 1;
			for (int j = i; j <= x; j++)
			{
				if (flag[j]) continue;
				if (j + k <= x)
				{
					a[j]--;
					if (a[j] == 0)
						pq.emplace(j);
				}
				else break;
			}
		}
		ans.push_back(pq.top());
		pq.pop();
		flag[i] = 1;
	}
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}
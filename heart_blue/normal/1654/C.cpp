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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		LL sum = 0;
		scanf("%d", &n);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x), sum += x;
		sort(v.begin(), v.end());
		priority_queue<LL> pq;
		pq.emplace(sum);
		while (!v.empty())
		{
			if (pq.top() == v.back())
			{
				v.pop_back();
				pq.pop();
				continue;
			}
			if (pq.top() < v.back()) break;
			LL x = pq.top();
			pq.pop();
			pq.emplace(x / 2);
			pq.emplace(x - x / 2);
		}
		if (v.empty()) puts("YES");
		else puts("NO");
	}
	return 0;
}
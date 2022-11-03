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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp(n);
	for (auto& p : vp) scanf("%d", &p.first);
	for (auto& p : vp) scanf("%d", &p.second);
	sort(vp.begin(), vp.end());
	vp.emplace_back(2 * int(INF), 2 * int(INF));
	priority_queue<int> pq;
	LL tot = 0;
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (vp[j].first == vp[i].first)
		{
			tot += vp[j].second;
			pq.push(vp[j++].second);
		}
		int cur = vp[i].first;
		while (cur < vp[j].first && !pq.empty())
		{
			tot -= pq.top();
			pq.pop();
			ans += tot;
			cur++;
		}
		i = j - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
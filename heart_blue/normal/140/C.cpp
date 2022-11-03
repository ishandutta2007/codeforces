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
const int N = 3e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	while (n--)
	{
		int x;
		cin >> x;
		mc[x]++;
	}
	vector<tuple<int, int, int>> ans;
	priority_queue<pair<int, int>> pq;
	for (auto &p : mc)
	{
		pq.push({ p.second,p.first });
	}
	while (pq.size() > 2)
	{
		auto p1 = pq.top();
		pq.pop();
		auto p2 = pq.top();
		pq.pop();
		auto p3 = pq.top();
		pq.pop();
		ans.push_back({ p1.second,p2.second,p3.second });
		p1.first--, p2.first--, p3.first--;
		if (p1.first > 0) pq.push(p1);
		if (p2.first > 0) pq.push(p2);
		if (p3.first > 0) pq.push(p3);
	}
	cout << ans.size() << endl;
	for (auto &p : ans)
	{
		int x, y, z;
		tie(x, y, z) = p;
		if (x < y) swap(x, y);
		if (y < z) swap(y, z);
		if (x < y) swap(x, y);
		printf("%d %d %d\n", x, y, z);
	}
	return 0;
}
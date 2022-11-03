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
pair<int, int> ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	deque<int> q;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		q.push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop_front();
		int y = q.front();
		q.pop_front();
		ans[i] = { x,y };
		if (x < y) swap(x, y);
		q.push_back(y);
		q.push_front(x);
	}
	vector<int> v(q.begin(), q.end());
	while (m--)
	{
		LL o;
		cin >> o;
		if (o <= n) printf("%d %d\n", ans[o].first, ans[o].second);
		else
		{
			o = (o - 2) % (n - 1) + 1;
			printf("%d %d\n", v[0], v[o]);
		}
	}
	return 0;
}
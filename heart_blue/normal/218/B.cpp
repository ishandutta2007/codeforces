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
const int N = 1e5 + 10;

int solve1(vector<int> &v, int m)
{
	int sum = 0;
	sort(v.begin(), v.end());
	for (auto x : v)
	{
		while (x&&m)
		{
			sum += x;
			x--, m--;
		}
	}
	return sum;
}
int solve2(vector<int> &v, int m)
{
	priority_queue <int> pq;
	for (auto x : v) pq.push(x);
	int sum = 0;
	while (m-- && !pq.empty())
	{
		int y = pq.top();
		pq.pop();
		sum += y--;
		if (y) pq.push(y);
	}
	return sum;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (auto &x : v) cin >> x;
	cout << solve2(v, n) << ' ' << solve1(v, n) << endl;

	return 0;
}
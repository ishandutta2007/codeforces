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
const int N = 2e5 + 10;
vector<tuple<int, int, int>> vp;
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	priority_queue<int,vector<int>,greater<int>> pq;
	LL sum = 0;
	cin >> n >> k;
	vp.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> get<0>(vp[i]);
		get<2>(vp[i]) = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> get<1>(vp[i]);
	}
	sort(vp.begin(), vp.end());
	for (auto &p : vp)
	{
		int x, y, pos;
		tie(x, y, pos) = p;
		sum += y;
		ans[pos] = sum;
		pq.push(y);
		while (pq.size() > k)
		{
			sum -= pq.top();
			pq.pop();
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
	return 0;
}
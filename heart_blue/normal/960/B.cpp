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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	int k = k1 + k2;
	for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[i] = abs(a[i] - x);
		pq.push(a[i]);
	}
	while (!pq.empty() && k > 0)
	{
		int x = pq.top();
		pq.pop();
		if (x == 0) continue;
		k--;
		pq.push(x - 1);
	}
	LL ans = k & 1;
	while (!pq.empty())
	{
		LL x = pq.top();
		pq.pop();
		ans += x * x;
	}
	cout << ans << endl;
	return 0;
}
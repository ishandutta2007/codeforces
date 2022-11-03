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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int maxv = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
		maxv = max(maxv, x);
	}

	maxv += m;
	while (m--)
	{
		int x = pq.top();
		pq.pop();
		pq.push(x + 1);
	}
	int ans = 0;
	while (pq.size() > 1) pq.pop();
	cout << pq.top() << ' ' << maxv << endl;
	return 0;
}
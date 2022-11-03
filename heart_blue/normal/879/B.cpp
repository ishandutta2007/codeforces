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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int maxv = *max_element(v.begin(), v.end());
	queue<int> q;
	for (auto &x : v) q.push(x);
	int x = q.front();
	q.pop();
	LL cnt = 0;
	while (1)
	{
		int y = q.front();
		q.pop();
		if (x < y) cnt = 0;
		cnt++;
		q.push(min(x, y));
		x = max(x, y);
		if (x == maxv || cnt == k) break;
	}
	cout << x << endl;
	return 0;
}
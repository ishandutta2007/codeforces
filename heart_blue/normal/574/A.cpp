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
const int N = 2e3+ 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int sum;
	cin >> n >> sum;
	priority_queue<int> pq;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	while (1)
	{
		int x = pq.top();
		pq.pop();
		if (sum > x) break;
		sum++;
		ans++;
		pq.push(x - 1);
	}
	cout << ans << endl;
	return 0;
}
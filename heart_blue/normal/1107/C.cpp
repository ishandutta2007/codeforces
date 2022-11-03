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
LL ans = 0;
int a[N];
char str[N];
priority_queue<int, vector<int>, greater<int>> pq;

void getans()
{
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	scanf("%s", str + 1);
	int cnt = 0;
	int pre = -1;
	for (int i = 1; i <= n; i++)
	{
		if (pre != str[i]) getans();
		pq.push(a[i]);
		if (pq.size() > k) pq.pop();
		pre = str[i];
	}
	getans();
	cout << ans << endl;
	return 0;
}
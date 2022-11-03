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
const int N = 2e2 + 10;
vector<int> ans[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int minv = INF;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		minv = min(minv, a[i]);
		maxv = max(maxv, a[i]);
	}
	if (maxv - minv > k)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int o = min(minv, a[i]);
		while (o--) ans[i].push_back(1);
		for (int j = minv + 1; j <= a[i]; j++)
		{
			ans[i].push_back(j - minv);
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (auto &x : ans[i])
		{
			cout << x << ' ';
		}
		cout << endl;
	}
	return 0;
}
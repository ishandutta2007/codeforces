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
const int N = 5e2 + 10;
int cnt[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		for (int j = 1; j <= m; j++)
		{
			if (x % a[j] == 0)
				cnt[j]++;
		}
	}
	int minv = INF;
	vector<int> ans;
	for (int i = 1; i <= m; i++)
	{
		minv = min(minv, cnt[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		if (minv == cnt[i])
			ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (auto& x : ans) cout << x << ' ';
	return 0;
}
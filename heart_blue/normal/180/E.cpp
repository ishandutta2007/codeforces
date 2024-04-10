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
vector<int> v[N];
int solve(vector<int>& v, int k)
{
	int ptr = 0;
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		while (ptr < v.size() && (v[ptr] - v[i]) - (ptr - i) <= k)
		{
			ans = max(ans, ptr - i + 1);
			ptr++;
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans = max(ans, solve(v[i], k));
	}
	cout << ans << endl;
	return 0;
}
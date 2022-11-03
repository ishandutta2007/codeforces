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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int s, r;
		cin >> s >> r;
		v[s].push_back(r);
	}
	for (int i = 1; i <= m; i++)
	{
		sort(v[i].rbegin(), v[i].rend());
		for (int j = 1; j < v[i].size(); j++)
		{
			v[i][j] += v[i][j - 1];
		}
		for (int j = 0; j < v[i].size(); j++) ans[j] += max(0, v[i][j]);
	}
	int res = 0;
	for (int i = 0; i < N; i++)
		res = max(res, ans[i]);
	cout << res << endl;
	return 0;
}
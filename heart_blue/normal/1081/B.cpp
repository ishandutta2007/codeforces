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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[n - x].push_back(i);
	}
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].empty()) continue;
		if (v[i].size() % i) puts("Impossible"), exit(0);
		for (int j = 0; j < v[i].size(); j++)
		{
			if (j % i == 0) ++c;
			ans[v[i][j]] = c;
		}
	}
	puts("Possible");
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}
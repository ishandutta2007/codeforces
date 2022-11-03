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
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	set<pair<int, int>> s;
	for (int i = 1; i <= n; i++)
	{
		for (int j = max(1, i - 1); j <= min(n, i + 1); j++)
		{
			s.emplace(i, j);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &a[i]);
		flag[a[i]] = 1;
		for (int j = a[i] - 1; j <= a[i] + 1; j++)
		{
			if (flag[j]) s.erase(make_pair(j, a[i]));
		}
	}
	cout << s.size() << endl;
	return 0;
}
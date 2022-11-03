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
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
		mc[sum[i]] = i;
	}
	vector<int> v;
	v.push_back(0);
	if (sum[n] % k) puts("No"), exit(0);
	int avg = sum[n] / k;
	for (int i = 1; i <= k; i++)
	{
		if (!mc.count(avg * i)) puts("No"), exit(0);
		v.push_back(mc[avg * i]);
	}
	puts("Yes");
	for (int i = 0; i + 1 < v.size(); i++)
	{
		printf("%d ", v[i + 1] - v[i]);
	}
	return 0;
}
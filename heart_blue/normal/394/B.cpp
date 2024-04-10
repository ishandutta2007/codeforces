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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
void solve(int cur, int x, int p)
{
	vector<int> v1;
	v1.push_back(cur);
	int o = 0;
	while (v1.size() < p)
	{
		int sum = v1.back() * x + o;
		v1.push_back(sum % 10);
		o = sum / 10;
	}
	vector<int> v2 = v1, ans = v1;
	v2.insert(v2.end(), v2.front());
	v2.erase(v2.begin());
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] *= x;
	}
	for (int i = 0; i + 1 < v1.size(); i++)
	{
		v1[i + 1] += v1[i] / 10;
		v1[i] %= 10;
	}
	if (v1 == v2)
	{
		reverse(ans.begin(), ans.end());
		if (ans[0] == 0) return;
		for (auto& x : ans)
			printf("%d", x);
		exit(0);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int p, x;
	scanf("%d%d", &p, &x);
	for (int i = 1; i < 10; i++)
		solve(i, x, p);
	puts("Impossible");
	return 0;
}
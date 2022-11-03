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
vector<int> v1, v2;
LL solve(vector<int>& v)
{
	LL sum1 = 0;
	LL sum2 = 0;
	for (auto& x : v) sum1 += x, sum2 += 1LL * x * x;
	return sum2 * (v.size() - 1) - sum1 * sum1 + sum2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		v1.push_back(x);
		v2.push_back(y);
	}
	cout << solve(v1) + solve(v2) << endl;
	return 0;
}
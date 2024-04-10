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
const int N = 2e5 + 10;
int refrain(vector<int>& v)
{
	for (auto& x : v)
		scanf("%d", &x);
	for (int i = 0; i + 1 < v.size(); i++)
		v[i] = v[i + 1] - v[i];
	int ret = v.back();
	v.pop_back();
	sort(v.begin(), v.end());
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> v1(n), v2(n);
	if (refrain(v1) != refrain(v2) || v1 != v2) puts("NO");
	else puts("YES");
	return 0;
}
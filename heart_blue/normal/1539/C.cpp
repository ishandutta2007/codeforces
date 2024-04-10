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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k, x;
	scanf("%d%lld%lld", &n, &k, &x);
	vector<LL> a(n), b;
	for (auto& x : a)
		scanf("%lld", &x);
	sort(a.begin(), a.end());
	for (int i = 1; i < a.size(); i++)
	{
		b.push_back(max(0LL, (a[i] - a[i - 1] - 1) / x));
	}
	int ans = n;
	sort(b.begin(), b.end());
	for (auto& t : b)
	{
		k -= t;
		if (k < 0) break;
		ans--;
	}
	printf("%d\n", ans);
	return 0;
}
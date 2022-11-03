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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n;
		scanf("%d", &n);
		map<int, int> mc;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		vector<int> v;
		for (auto& [val, cnt] : mc)
		{
			v.push_back(min(cnt, 2));
		}
		int cnt1 = count(v.begin(), v.end(), 1);
		int cnt2 = v.size() - cnt1;
		int ans = 0;
		if (cnt1 == 0) ans = cnt2;
		else
		{
			ans = max(ans, cnt2 + cnt1 / 2);
			ans = max(ans, cnt2 + 1 + (cnt1 - 1) / 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}
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
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		mc[x]++;
	}
	vector<int> v;
	for (auto &p : mc) v.push_back(p.second);
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		while (!v.empty() && v.back() < i) v.pop_back();
		int sum = 0;
		int cur = i;
		for (auto iter = v.rbegin(); iter != v.rend(); iter++)
		{
			if (cur <= *iter)
			{
				sum += cur;
				cur <<= 1;
			}
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}
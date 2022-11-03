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
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> ans;
	int l = 1, r = n / k;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
		if (ans.size() < k) ans.push_back(x);
	}
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		vector<int> tmp;
		for (int i = 1; i < N; i++)
		{
			int o = cnt[i] / mid;
			while (o--) tmp.push_back(i);
		}
		if (tmp.size() >= k) ans = tmp, l = mid + 1;
		else r = mid - 1;
	}
	while (ans.size() > k) ans.pop_back();
	for (auto &x : ans) printf("%d ", x);
	return 0;
}
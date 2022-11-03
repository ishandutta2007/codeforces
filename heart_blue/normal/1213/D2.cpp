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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());
	for (auto& x : v)
	{
		int o = 0;
		while (x)
		{
			if (cnt[x] < k)
			{
				cnt[x]++;
				ans[x] += o;
			}
			x /= 2;
			o++;
		}
	}
	int res = INF;
	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == k)
			res = min(res, ans[i]);
	}
	cout << res << endl;
	return 0;
}
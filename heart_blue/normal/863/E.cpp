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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int sum[N];
int refrain(vector<pair<int, int>>& vp)
{
	vector<int> v;
	for (auto [l, r] : vp)
	{
		v.push_back(l);
		v.push_back(r);
		v.push_back(l - 1);
		v.push_back(r + 1);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto& [l, r] : vp)
	{
		l = lower_bound(v.begin(), v.end(), l) - v.begin() + 1;
		r = lower_bound(v.begin(), v.end(), r) - v.begin() + 1;
	}
	return v.size();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp(n);
	for (auto& [l, r] : vp)
	{
		scanf("%d%d", &l, &r);
	}
	int tot = refrain(vp);
	for (auto& [l, r] : vp)
	{
		sum[l]++;
		sum[r + 1]--;
	}
	for (int i = 1; i <= tot; i++)
	{
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= tot; i++)
	{
		if (sum[i] > 1) sum[i] = 1;
		else sum[i] = 0;
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i < vp.size(); i++)
	{
		auto [l, r] = vp[i];
		if (sum[r] - sum[l - 1] == r - l + 1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
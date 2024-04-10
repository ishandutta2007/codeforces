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
const int N = 2e4 + 10;
int sum[N];
vector<int> v;
vector<pair<int, int>> vp;
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		vp.emplace_back(l, r);
		v.push_back(l);
		v.push_back(r);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto& p : vp)
	{
		int l, r;
		tie(l, r) = p;
		l = lower_bound(v.begin(), v.end(), l) - v.begin() + 1;
		r = lower_bound(v.begin(), v.end(), r) - v.begin() + 1;

p={l,r};
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	init(n);
	vector<int> ans;
	for (int i = 0; i < vp.size(); i++)
	{
		MEM(sum, 0);
		for (int j = 0; j < vp.size(); j++)
		{
			if (i == j) continue;
			int l, r;
			tie(l, r) = vp[j];
			sum[l]++;
			sum[r]--;
		}
		int flag = 1;
		if (sum[0] > 1) flag = 0;
		for (int i = 1; i < N; i++)
		{
			sum[i] += sum[i - 1];
			if (sum[i] > 1) flag = 0;
		}
		if (flag) ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x + 1);
	return 0;
}
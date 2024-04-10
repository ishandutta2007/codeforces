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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
void refrain(vector<int>& a)
{
	vector<int> key = a;
	sort(key.begin(), key.end());
	key.resize(unique(key.begin(), key.end()) - key.begin());
	for (auto& x : a)
		x = lower_bound(key.begin(), key.end(), x) - key.begin() + 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (auto& x : a)
			scanf("%d", &x);
		refrain(a);
		int maxv = *max_element(a.begin(), a.end());
		for (int i = 1; i <= maxv + 1; i++) v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			v[a[i - 1]].push_back(i);
		}
		int ans = 0;
		for (int i = 1; i <= maxv; i++)
		{
			int tot = v[i].size();
			int ptr = i + 1;
			while (ptr <= maxv && v[ptr].front() > v[ptr - 1].back())
			{
				tot += v[ptr].size();
				ptr++;
			}
			ptr--;
			tot += lower_bound(v[i - 1].begin(), v[i - 1].end(), v[i].front()) - v[i - 1].begin();
			tot += v[ptr + 1].end() - lower_bound(v[ptr + 1].begin(), v[ptr + 1].end(), v[ptr].back());
			ans = max(ans, tot);
			i = ptr;
		}
		for (int i = 2; i <= maxv; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				int tot = v[i].size() - j;
				tot += lower_bound(v[i - 1].begin(), v[i - 1].end(), v[i][j]) - v[i - 1].begin();
				ans = max(ans, tot);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
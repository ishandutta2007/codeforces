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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e4 + 10;
int solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	reverse(v.begin(), v.end());
	int ans = v.front();
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 1; j < 500 && i + j < v.size(); j++)
		{
			if (v[i] % v[j] != 0)
				ans = max(ans, v[i] + v[j]);
		}
	}
	while (v.size() > 500) v.pop_back();
	n = v.size();
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] % v[j] == 0) continue;
			for (int k = j + 1; k < v.size(); k++)
			{
				if (v[i] + v[j] + v[k] <= ans) break;
				if (v[i] % v[k] == 0 || v[j] % v[k] == 0) continue;
				ans = max(ans, v[i] + v[k] + v[j]);
				break;
			}
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		printf("%d\n", solve());
	}
	return 0;
}
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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int check(vector<int>& v1, vector<int>& v2)
{
	int tot = max(v1.back(), v2.back());
	for (auto& x : v1) x = tot - x + 1;
	for (auto& x : v2) x = tot - x + 1;
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	int ans = 0;
	int ptr = 0;
	for (auto& x : v1)
	{
		while (ptr < v2.size() && x > v2[ptr]) ptr++;
		if (ptr == v2.size()) break;
		ans++;
		ptr++;
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
		int n;
		scanf("%d", &n);
		vector<int> v1(n), v2;
		for (auto& x : v1) scanf("%d", &x);
		v1.push_back(2 * n + 1);
		int cur = 1;
		for (auto& x : v1)
		{
			while (cur < x)
			{
				v2.push_back(cur++);
			}
			cur++;
		}
		v1.pop_back();
		int l = n-check(v1, v2);
		int r = check(v1, v2);
		printf("%d\n", r - l + 1);
	}
	return 0;
}
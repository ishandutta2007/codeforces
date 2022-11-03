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
const int N = 4e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int k, n, m;
		scanf("%d%d%d", &k, &n, &m);
		vector<int> v1(n), v2(m);
		for (auto& x : v1) scanf("%d", &x);
		for (auto& x : v2) scanf("%d", &x);
		vector<int> ans;
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		int flag = 1;
		while (!v1.empty() || !v2.empty())
		{
			flag = 0;
			while (!v1.empty() && v1.back() <= k)
			{
				ans.push_back(v1.back());
				if (v1.back() == 0) k++;
				v1.pop_back();
				flag = 1;
			}
			while (!v2.empty() && v2.back() <= k)
			{
				ans.push_back(v2.back());
				if (v2.back() == 0) k++;
				v2.pop_back();
				flag = 1;
			}
			if (flag == 0) break;
		}
		if (!flag) ans = vector<int>(1, -1);
		for (auto& x : ans) printf("%d ", x);
		puts("");
	}
	return 0;
}
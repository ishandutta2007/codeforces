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
const int N = 1e5 + 10;
tuple<int, int, int> a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		int cnt0 = count(str.begin(), str.end(), '0');
		int cnt1 = n - cnt0;
		int key = cnt0 - cnt1;
		int ans = 0;
		int sum = 0;
		for (auto& c : str)
		{
			if (c == '1') sum--;
			else sum++;
			if (sum == k && key == 0)
			{
				ans = -1;
				break;
			}
			if (key == 0) continue;
			int o = k - sum;
			if (o % key == 0 && o / key >= 0) ans++;
		}
		if (ans != -1 && k == 0) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
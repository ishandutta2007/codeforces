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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		int n = str.length();
		vector<int> v;
		v.push_back(-1);
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '0')
				v.push_back(i);
		}
		v.push_back(n);
		if (v.size() == 2 || v.size() == n + 2)
		{
			puts("0");
			continue;
		}
		int L1 = str.find_first_of('1');
		int R1 = str.find_last_of('1');
		int cnt1 = count(str.begin(), str.end(), '1');
		if (R1 - L1 + 1 == cnt1)
		{
			puts("0");
			continue;
		}
		int l = 1, r = v.size() - 2;
		int ans = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int tot1 = 0;
			for (int i = 1; i + mid < v.size(); i++)
			{
				int rest = v[i + mid] - v[i - 1] - 1 - mid;
				tot1 = max(tot1, rest);
			}
			if (cnt1 - tot1 <= mid) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
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
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.rbegin(), s2.rend());
	int n = s1.length();
	list<char> lc1, lc2;

	for (int i = 0; i < (n + 1) / 2; i++) lc1.push_back(s1[i]);
	for (int i = 0; i < n / 2; i++) lc2.push_back(s2[i]);
	string ans(n, ' ');
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
		{
			if (lc1.front() >= lc2.front()) ans[r--] = lc2.back(), lc2.pop_back();
			else ans[l++] = lc2.front(), lc2.pop_front();
		}
		else
		{
			if (lc2.empty())
			{
				ans[l++] = lc1.front();
				continue;
			}
			if (lc1.front() < lc2.front()) ans[l++] = lc1.front(), lc1.pop_front();
			else ans[r--] = lc1.back(), lc1.pop_back();
		}
	}
	cout << ans << endl;

	return 0;
}
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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string s1, s2;
		int n, m, k;
		cin >> n >> m >> k;
		cin >> s1 >> s2;
		sort(s1.rbegin(), s1.rend());
		sort(s2.rbegin(), s2.rend());
		if (s1.back() > s2.back())
			swap(s1, s2);
		string ans;
		while (!s1.empty() && !s2.empty())
		{
			for (int i = 0; i < k && !s1.empty() && s1.back() < s2.back(); i++)
			{
				ans += s1.back();
				s1.pop_back();
			}
			if (s1.empty() || s2.empty()) break;
			if (s1.back() > s2.back())
			{
				swap(s1, s2);
				continue;
			}
			ans += s2.back();
			s2.pop_back();
		}
		cout << ans << endl;
	}
	return 0;
}
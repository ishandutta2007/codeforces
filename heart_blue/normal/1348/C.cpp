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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		map<char, int> mc;
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		int cnt1 = count(str.begin(), str.end(), str[0]);
		if (cnt1 < k)
		{
			putchar(str[k - 1]);
			puts("");
			continue;
		}
		if (k != n && count(str.begin() + k, str.end(), str[k]) + k == n)
		{
			for (int i = 0; i < n; i += k)
				putchar(str[i]);
			puts("");
		}
		else
		{
			putchar(str[0]);
			puts(str.substr(k).c_str());
		}
	}

	return 0;
}
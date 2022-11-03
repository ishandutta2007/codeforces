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
const int N = 3e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string s1, s2;
		int n;
		cin >> n;
		cin >> s1 >> s2;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] == '0' || s2[i] == '0') ans++;
			if (s1[i] - '0' + s2[i] - '0' == 1) ans++;
		}
		for (int i = 0; i + 1 < n; i++)
		{
			int x = (s1[i] - '0') * 2 + s2[i] - '0';
			int y = (s1[i + 1] - '0') * 2 + s2[i + 1] - '0';
			if (x > y) swap(x, y);
			if (x == 0 && y == 3) ans++, i++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
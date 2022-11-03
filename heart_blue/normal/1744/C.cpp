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
const int N = 1e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
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
		char ch;
		scanf("%d %c", &n, &ch);
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		str += str;
		int ans = 0;
		int cnt = 0;
		for (auto& c : str)
		{
			if (c == 'g') cnt = 0;
			else cnt++;
			if (c == ch) ans = max(ans, cnt);
		}
		printf("%d\n", ans);
		reverse(str.begin(), str.end());
	}
	return 0;
}
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
int check(string s1, int x)
{
	int tot = 0;
	while (x)
	{
		while (!s1.empty() && s1.back() != x % 10 + '0') s1.pop_back();
		if (s1.empty()) return -1;
		tot++;
		s1.pop_back();
		x /= 10;
	}
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int ans = -1;
	for (int i = 1; i * i < 2 * INF; i++)
	{
		ans = max(ans, check(str, i*i));
	}
	if (ans != -1) ans = str.length() - ans;
	cout << ans << endl;
	return 0;
}
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
int check(string str, char x, char y)
{
	int ans = 0;
	int n = str.length();
	int o = str.find_last_of(y);
	if (o == -1) return INF;
	for (int i = o; i + 1 < n; i++) swap(str[i], str[i + 1]), ans++;
	o = str.substr(0, n - 1).find_last_of(x);
	if (o == -1) return INF;
	for (int i = o; i + 2 < n; i++) swap(str[i], str[i + 1]), ans++;
	o = str.find_first_not_of('0');
	while (o > 0) swap(str[o], str[o - 1]), ans++, o--;
	return ((str[n - 2] - '0') * 10 + str[n - 1] - '0') % 25 == 0 ? ans : int(INF);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int ans = min(min(check(str, '5', '0'), check(str, '2', '5')),
		min(check(str, '0', '0'), check(str, '7', '5')));
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}
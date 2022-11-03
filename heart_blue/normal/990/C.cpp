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
int check(string &str, char ch = '(')
{
	int o = 0;
	for (auto &c : str)
	{
		if (c == ch) o++;
		else o--;
		if (o < 0) return -1;
	}
	return o;
}
map<int, int> mc1, mc2;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		mc1[check(str, '(')]++;
		reverse(str.begin(), str.end());
		mc2[check(str, ')')]++;
	}
	mc1.erase(-1);
	mc2.erase(-1);
	LL ans = 0;
	for (auto &p : mc1)
	{
		ans += 1LL * p.second*mc2[p.first];
	}
	cout << ans << endl;
	return 0;
}
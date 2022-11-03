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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
bool check(string &s1, string &s2)
{
	if (s1.length() != s2.length()) return false;
	if (s1 == s2) return true;
	int c1 = 0, c2 = 0;
	for (auto ch : s1) c1 |= ch - '0';
	for (auto ch : s2) c2 |= ch - '0';
	return c1 & c2;;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	if (check(s1, s2)) puts("YES");
	else puts("NO");
	return 0;
}
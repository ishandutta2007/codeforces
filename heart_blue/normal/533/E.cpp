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
const int N = 4e5 + 10;
void check(string &s1, string &s2)
{
	while (s1.back() == s2.back()) s1.pop_back(), s2.pop_back();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	check(s1, s2);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	check(s1, s2);
	n = s1.length();
	if (n == 1)
	{
		puts("2");
		return 0;
	}
	int ans = 0;
	if (s1.substr(0, n - 1) == s2.substr(1, n - 1)) ans++;
	if (s1.substr(1, n - 1) == s2.substr(0, n - 1)) ans++;
	printf("%d\n", ans);
	return 0;
}
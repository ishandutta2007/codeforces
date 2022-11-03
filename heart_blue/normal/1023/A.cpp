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
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.find('*') == s1.npos)
	{
		if (s1 == s2) puts("YES");
		else puts("NO");
		return 0;
	}
	int pos = s1.find('*');
	string str1 = s1.substr(0, pos);
	string str2 = s1.substr(pos + 1);
	if (str1.length() + str2.length() > s2.length())
	{
		puts("NO");
		return 0;
	}
	if (s2.substr(0, str1.length()) == str1 &&
		s2.substr(s2.length() - str2.length()) == str2) puts("YES");
	else puts("NO");
	return 0;
}
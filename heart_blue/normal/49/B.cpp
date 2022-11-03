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
const int N = 2e3 + 10;
string s1, s2;
int check(int b)
{
	int n = s1.length();
	string s = s1;
	for (int i = n - 1; i >= 0; i--)
	{
		s[i] += s2[i] - '0';
		if (s[i] >= b + '0')
		{
			if (i == 0) return 1;
			s[i - 1]++;
		}
	}
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s1 >> s2;
	int n = max(s1.length(), s2.length());
	s1 = string(n - s1.length(), '0') + s1;
	s2 = string(n - s2.length(), '0') + s2;
	int ans = 0;
	int b = 0;
	for (auto &c : s1) b = max(b, c - '0');
	for (auto &c : s2) b = max(b, c - '0');
	for (int i = b + 1; i <= 20; i++)
	{
		if (check(i))
		{
			cout << n + 1 << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}
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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
string add(string s1, string s2)
{
	if (s1.length() < s2.length()) swap(s1, s2);
	s2 = string(s1.length() - s2.length() + 1, '0') + s2;
	s1 = "0" + s1;
	int o = 0;
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		s1[i] += o + s2[i] - '0';
		o = 0;
		if (s1[i] > '9')
			s1[i] -= 10, o = 1;
	}
	if (s1[0] == '0') s1 = s1.substr(1);
	return s1;
}
string getmin(string s1, string s2)
{
	if (s1.length() < s2.length()) return s1;
	else if (s1.length() > s2.length()) return s2;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] < s2[i])
		{
			return s1;
		}
		if (s1[i] > s2[i])
		{
			return s2;
		}
	}
	return s1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	vector<pair<int, int>> vp;
	for (int i = 1; i < n; i++)
	{
		if (str[i] != '0')
		{
			vp.emplace_back(max(i, n - i), i);
		}
	}
	sort(vp.begin(), vp.end());
	string ans = string(n, '9');
	for (int i = 0; i < min(10, int(vp.size())); i++)
	{
		int p = vp[i].second;
		ans = getmin(ans, add(str.substr(0, p), str.substr(p)));
	}
	cout << ans << endl;
	return 0;
}
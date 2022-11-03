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
const int N = 5e3 + 10;
int a[10];
int cnt1[10];
int cnt2[10];
tuple <int, string, string> ans;
void check(int x)
{
	if (a[x] == 0 || a[10 - x] == 0) return;
	memcpy(cnt1, a, sizeof(cnt1));
	memcpy(cnt2, a, sizeof(cnt2));
	string s1, s2;
	cnt1[x]--, cnt2[10 - x]--;
	s1.push_back(x + '0');
	s2.push_back(10 - x + '0');
	for (int i = 0; i <= 9; i++)
	{
		int o = min(cnt1[i], cnt2[9 - i]);
		for (int j = 0; j < o; j++) s1.push_back(i + '0'), s2.push_back(9 - i + '0');
		cnt1[i] -= o;
		cnt2[9 - i] -= o;
	}
	int o = min(cnt1[0], cnt2[0]);
	s1 = string(o, '0') + s1;
	s2 = string(o, '0') + s2;
	int cnt = s1.length();
	cnt1[0] -= o;
	cnt2[0] -= o;
	for (int i = 0; i < 10; i++)
	{
		while (cnt1[i]--) s1.push_back(i + '0');
		while (cnt2[i]--) s2.push_back(i + '0');
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	ans = max(ans, make_tuple(cnt, s1, s2));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	sort(str.rbegin(), str.rend());
	for (auto& c : str)
	{
		a[c - '0']++;
	}
	ans = make_tuple(0, str, str);
	for (int i = 1; i <= 9; i++)
		check(i);
	string s1, s2;
	tie(ignore, s1, s2) = ans;
	puts(s1.c_str());
	puts(s2.c_str());
		return 0;
}
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
const int N = 1e4 + 10;
const int maxv = 9999;
int flag[N];
int check(int x)
{
	string s = to_string(x);
	s = string(4 - s.length(), '0') + s;
	sort(s.begin(), s.end());
	for (int i = 0; i + 1 < s.length(); i++)
	{
		if (s[i] == s[i + 1]) return 0;
	}
	return 1;
}
void init()
{
	for (int i = 0; i <= maxv; i++)
	{
		flag[i] = check(i);
	}
}
pair<int, int> check(int x, int y)
{
	string s1 = to_string(x);
	string s2 = to_string(y);
	s1 = string(4 - s1.length(), '0') + s1;
	s2 = string(4 - s2.length(), '0') + s2;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = '0'; i <= '9'; i++)
	{
		if (s1.find(i) != s1.npos && s2.find(i) != s2.npos)
			cnt2++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (s1[i] == s2[i])
			cnt1++;
	}
	cnt2 -= cnt1;
	return { cnt1,cnt2 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	init();
	while (n--)
	{
		int x;
		int a, b;
		cin >> x >> a >> b;
		for (int i = 0; i <= maxv; i++)
		{
			if (flag[i] == 0) continue;
			if (check(i, x) != make_pair(a, b))
			{
				flag[i] = 0;
			}
		}
	}
	int cnt = count(flag, flag + N, 1);
	if (cnt == 1)
	{
		printf("%04d\n", find(flag, flag + N, 1) - flag);
	}
	else if (cnt == 0)
	{
		cout << "Incorrect data" << endl;
	}
	else
	{
		cout << "Need more data" << endl;
	}
	return 0;
}
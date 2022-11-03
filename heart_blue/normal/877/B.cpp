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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	str.push_back('1');
	int cnt = 1;
	vector<int> v;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] != str[i - 1]) v.push_back(cnt), cnt = 0;
		cnt++;
	}
	if (v.size() <= 2)
	{
		cout << str.length() - 1 << endl;
		return 0;
	}
	int a = 0, b = 0;
	str.pop_back();
	for (auto &c : str)
	{
		if (c == 'a') a++;
		else b++;
	}
	int ans = max(a, b);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'a') continue;
		int cnta = 0;
		int cntb = 0;
		for (int j = i; j < str.length(); j++)
		{
			if (str[j] == 'b')
			{
				cntb++;
				ans = max(ans, cntb + a - cnta);
			}
			else cnta++;
		}
	}
	cout << ans << endl;
	return 0;
}
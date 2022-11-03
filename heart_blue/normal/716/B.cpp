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
const int N = 2e2 + 10;
int flag[N];
bool check(string &s)
{
	MEM(flag, 0);
	map<int, int> m;
	for (auto &c : s) m[c] ++, flag[c] = 1;
	int f = 0;
	if (m.count('?'))
	{
		if (m.size() - 1 + m['?'] == 26)
		{
			f = 1;
		}
	}
	else
	{
		if (m.size() == 26) f = 1;
	}
	int l = 'A';
	for (auto &c : s)
	{
		if (c == '?')
		{
			while (flag[l]) l++;
			flag[l] = 1;
			c = l;
		}
	}
	return f;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int flag = 0;
	for (int i = 0; i + 26 <= str.length(); i++)
	{
		string s = str.substr(i, 26);
		if (check(s))
		{
			for (int j = 0; j < 26; j++)
			{
				str[i + j] = s[j];

			}
			for (auto &c : str) if (c == '?') c = 'A';
			flag = 1;
			break;
		}
	}
	if (flag) cout << str << endl;
	else cout << -1 << endl;
	return 0;
}
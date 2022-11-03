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
void build(string& str, int pos)
{
	for (auto& c : str)
		if (c == '?')
			c = 'z';
}
bool check(string str, int pos)
{
	string key = "abacaba";
	if (pos + 7 > str.length()) return false;
	for (int i = 0; i < 7; i++)
	{
		if (str[i + pos] == '?')
			str[i + pos] = key[i];
		if (str[i + pos] != key[i])
			return false;
	}
	pos = str.find(key);
	pos = str.find(key, pos + 1);
	return pos == -1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int len;
		cin >> len;
		string str;
		cin >> str;
		int ok = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (check(str, i))
			{
				for (int j = 0; j < 7; j++)
					str[i + j] = "abacaba"[j];
				build(str, i);
				ok = 1;
				break;
			}
		}
		if (ok) puts("Yes"), puts(str.c_str());
		else puts("No");
	}
	return 0;
}
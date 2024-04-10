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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int len;
	cin >> len;
	int mask = (1 << 26) - 1;
	string str;
	cin >> str;
	int o = 0;
	for (auto& c : str)
	{
		if (c != '*')
			o |= 1 << (c - 'a');
	}
	int cur = o;
	o ^= mask;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int oo = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != '*')
			{
				if (str[i] != s[i])
				{
					oo = mask;
					break;
				}
				continue;
			}
			if (cur >> (s[i] - 'a') & 1)
			{
				oo = mask;
				break;
			}
			oo |= 1 << (s[i] - 'a');
		}
		o &= oo;
	}
	int cnt = 0;
	while (o) o -= o & -o, cnt++;
	cout << cnt << endl;
	return 0;
}
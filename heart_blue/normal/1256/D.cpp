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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		int n;
		LL k;
		cin >> n >> k;
		cin >> str;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '0')
			{
				if (cnt1 <= k)
				{
					k -= cnt1;
				}
				else
				{
					cout << string(cnt0, '0');
					cout << string(cnt1 - k, '1');
					cout << '0';
					cout << string(k, '1');
					cout << str.substr(i + 1) << '\n';
					break;
				}
			}
			if (str[i] == '0') cnt0++;
			else cnt1++;
			if (i + 1 == str.length())
			{
				cout << string(cnt0, '0');
				cout << string(cnt1, '1') << '\n';
			}
		}
	}
	return 0;
}
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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		string ans;
		while (!str.empty())
		{
			char c = str.back();
			str.pop_back();
			if (c != '0')
			{
				ans += c - '0' + 'a' - 1;
			}
			else
			{
				char c1 = str.back() - '0';
				str.pop_back();
				char c2 = str.back() - '0';
				str.pop_back();
				ans += (c2 * 10 + c1) + 'a' - 1;
			}
		}
		reverse(ans.begin(), ans.end());
		puts(ans.c_str());
	}
	return 0;
}
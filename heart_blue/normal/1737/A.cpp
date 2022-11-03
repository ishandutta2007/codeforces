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
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		string str;
		cin >> str;
		map<char, int> mc;
		for (auto& x : str)
			mc[x]++;
		string ans(k, '0');
		for (int i = 0; i < n / k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				char c = i + 'a';
				if (ans[j] != '0') continue;
				if (mc[c] > 0)
				{
					mc[c]--;
				}
				else
				{
					ans[j] = i + 'a';
				}
			}
		}
		for (auto& c : ans)
		{
			if (c == '0')
				c = n / k + 'a';
		}
		puts(ans.c_str());

	}
	return 0;
}
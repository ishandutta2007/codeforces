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
		int n;
		cin >> n;
		vector<string> vs;
		map<string, int> ms;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			ms[str]++;
			vs.push_back(str);
		}
		int ans = 0;
		for (auto& s : vs)
		{
			if (ms[s] == 1) continue;
			ms[s]--;
			ans++;
			for (int i = '0'; i <= '9'; i++)
			{
				s[0] = i;
				if (ms[s] == 0)
				{
					ms[s] = 1;
					break;
				}
			}
		}
		printf("%d\n", ans);
		for (auto& s : vs)
			puts(s.c_str());
	}
	return 0;
}
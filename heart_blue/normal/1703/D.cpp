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
const int N = 5e2 + 10;
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
		vector<string> vs(n);
		map<string, int> ms;
		for (auto& s : vs)
			cin >> s, ms[s] = 1;
		for (int i = 0; i < vs.size(); i++)
		{
			int flag = 0;
			for (int j = 1; j < vs[i].length(); j++)
			{
				string s1 = vs[i].substr(0, j);
				string s2 = vs[i].substr(j);
				if (ms.count(s1) && ms.count(s2))
				{
					flag = 1;
					break;
				}
			}
			putchar(flag + '0');
		}
		puts("");
	}
	return 0;
}
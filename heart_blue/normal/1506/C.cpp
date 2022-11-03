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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int ans = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			for (int j = 0; j < s2.length(); j++)
			{
				int p1 = i;
				int p2 = j;
				int cnt = 0;
				while (p1 < s1.length() && p2 < s2.length() && s1[p1] == s2[p2])
					p1++, p2++, cnt += 2;
				ans = max(ans, cnt);
			}
		}
		printf("%d\n", s1.length() + s2.length() - ans);
	}
	return 0;
}
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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		string ans;
		for (auto& c : str)
		{
			if (c == 'A') ans.push_back(c);
			else
			{
				if (!ans.empty() && ans.back() == 'A') ans.pop_back();
				else ans.push_back(c);
			}
		}
		int cnt = count(ans.begin(), ans.end(), 'B');
		printf("%d\n", ans.length() - cnt + (cnt & 1));
	}
	return 0;
}
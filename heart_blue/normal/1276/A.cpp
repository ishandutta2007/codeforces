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
const int N = 2e5 + 20;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		scanf("%s", str + 1);
		vector<int> ans;
		for (int i = 1; str[i]; i++)
		{
			if (string(str + i, str + i + 5) == "twone")
				str[i + 2] = ' ', ans.push_back(i + 2);
		}
		for (int i = 2; str[i]; i++)
		{
			string s = string(str + i - 1, str + i + 2);
			if (s == "one" || s == "two")
				ans.push_back(i);
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (auto& x : ans)
			cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
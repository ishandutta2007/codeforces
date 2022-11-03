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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		while (!str.empty() && str.back() == '0') str.pop_back();
		while (!str.empty() && str.back() == '1') str.pop_back();
		int ans = 0;
		if (str.empty()) ans = -1;
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] != str[i - 1])
				ans++;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
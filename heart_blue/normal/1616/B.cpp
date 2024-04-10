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
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		string str;
		cin >> n >> str;
		string ans;
		ans.push_back(str[0]);
		for (int i = 1; i < n; i++)
		{
			if (str[i] > ans.back()) break;
			if (str[i] == ans.back() && str[i] == ans.front()) break;
			ans += str[i];
		}
		for (int i = ans.length() - 1; i >= 0; i--)
			ans += str[i];
		puts(ans.c_str());
	}
	return 0;
}
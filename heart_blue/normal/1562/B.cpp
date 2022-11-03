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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int flag[N];
string ans;
void init()
{
	flag[1] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = i + i; j < N; j += i)
			flag[j] = 1;
	}
}
bool check(string& str, int cur, int limit, int sum)
{
	if (limit == 0) return flag[sum] == 1;
	if (cur == str.length()) return false;
	if (check(str, cur + 1, limit, sum)) return true;
	ans += str[cur];
	if (check(str, cur + 1, limit - 1, sum * 10 + str[cur] - '0')) return true;
	ans.pop_back();
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int len;
		string str;
		cin >> len >> str;
		for (int i = 1; i <= len; i++)
		{
			ans.clear();
			if (check(str, 0, i, 0))
				break;
		}
		printf("%d\n", ans.length());
		puts(ans.c_str());
	}
	return 0;
}
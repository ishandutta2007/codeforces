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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	string str;
	cin >> str;
	int sum1 = 0, sum2 = 0;
	int mark1 = 0, mark2 = 0;
	int l = 0, r = str.length() - 1;
	while (l <= r)
	{
		if (str[l] == '?') mark1++;
		else sum1 += str[l] - '0';
		if (str[r] == '?') mark2++;
		else sum2 += str[r] - '0';
		l++, r--;
	}
	if (sum1 < sum2) swap(sum1, sum2), swap(mark1, mark2);
	if (mark1 > mark2) puts("Monocarp"), exit(0);
	int mark = mark2 - mark1;
	int sum = sum1 - sum2;
	mark /= 2;
	if (sum == mark * 9) puts("Bicarp");
	else puts("Monocarp");
	return 0;
}
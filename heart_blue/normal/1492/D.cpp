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
	int a, b, k;
	cin >> a >> b >> k;
	if (k == 0)
	{
		puts("Yes");
		string s = string(b, '1') + string(a, '0');
		puts(s.c_str());
		puts(s.c_str());
		return 0;
	}
	if (a == 0 || b == 1)
	{
		puts("No");
		return 0;
	}
	if (k >= a + b - 1)
	{
		puts("No");
		return 0;
	}
	string s1, s2;
	s1 = "11" + string(a - 1, '0') + string(b - 2, '1') + "0";
	s2 = "1" + string(a, '0') + string(b - 1, '1');
	int cur = a + b - 2;
	
	int ptr = 1;
	while (cur > k)
	{
		swap(s1[ptr], s1[ptr + 1]);
		swap(s2[ptr], s2[ptr + 1]);
		ptr++;
		cur--;
	}
	puts("Yes");
	puts(s1.c_str());
	puts(s2.c_str());
	return 0;
}
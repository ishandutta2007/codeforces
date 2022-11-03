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
	int n;
	cin >> n;
	if (n & 1)
	{
		puts("No");
		return 0;
	}
	string str;
	cin >> str;
	int flag = 0;
	int o = 0;
	for (auto& c : str)
	{
		if (c == '(') o++;
		else o--;
		if (o < 0)
		{
			if (flag) puts("No"), exit(0);
			o = 0;
			flag = 1;
		}
	}
	o -= flag;
	if (o == 0) puts("Yes");
	else puts("No");
	return 0;
}
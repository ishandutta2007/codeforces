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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*
	 v (ASCII code 118, lowercase v), < (ASCII code 60), ^ (ASCII code 94) or > (ASCII code 62) 
	*/
	a[118] = 0;
	a[60] = 1;
	a[94] = 2;
	a[62] = 3;
	char c1, c2;
	cin >> c1 >> c2;
	int n;
	cin >> n;
	int x = a[c1], y = a[c2];
	int flag1 = (x + n) % 4 == y;
	int flag2 = ((x - n) % 4 + 4) % 4 == y;
	if (flag1 ^ flag2)
	{
		if (flag1) puts("cw");
		else puts("ccw");
	}
	else puts("undefined");
	return 0;
}
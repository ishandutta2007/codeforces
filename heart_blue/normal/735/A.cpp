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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int n, k;
bool solve(string &str)
{
	int x, o;
	o = -1;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'G') o = i;
	}
	x = o;
	while (x < n)
	{
		if (str[x] == '#') break;
		if (str[x] == 'T') return true;
		x += k;
	}
	x = o;
	while (x >= 0)
	{
		if (str[x] == '#') break;
		if (str[x] == 'T') return true;
		x -= k;
	}
	return false;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	string str;
	cin >> str;
	if (solve(str)) puts("YES");
	else puts("NO");
	return 0;
}
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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int u, r, d, l;
	if (str.length() % 2 == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		u = r = d = l = 0;
		for (auto &c : str)
		{
			if (c == 'U') u++;
			if (c == 'D') d++;
			if (c == 'R') r++;
			if (c == 'L') l++;
		}
		cout << abs(u - d) / 2 + abs(l - r) / 2 + abs(l - r) % 2 << endl;
	}
	return 0;
}
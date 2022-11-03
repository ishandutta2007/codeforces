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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int p1, p2;
	p1 = p2 = -1;
	int ans = 1;
	for (auto &c : str)
	{
		if (c == 'L' || c == 'R')
		{
			if (p1 == -1) p1 = c;
			else if (p1 != c)
			{
				ans++;
				p1 = c;
				p2 = -1;
			}
		}
		if (c == 'U' || c == 'D')
		{
			if (p2 == -1) p2 = c;
			else if (p2 != c)
			{
				ans++;
				p2 = c;
				p1 = -1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
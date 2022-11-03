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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	map<int, int> mc;
	int o = 0;
	while (1)
	{
		o++;
		if (mc.count(a)) break;
		mc[a] = 1;
		a *= 10;
		if (a / b == c)
		{
			cout << o << endl;
			return 0;
		}
		a %= b;
	}
	cout << -1 << endl;
	return 0;
}
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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int k;
	int n;
	cin >> n >> k;
	cin >> str;
	int a = 'a';
	int z = 'z';
	for (auto &c : str)
	{
		if (c - a >= z - c)
		{
			int o = min(c - a, k);
			k -= o;
			c -= o;
		}
		else
		{
			int o = min(z - c, k);
			k -= o;
			c += o;
		}
	}
	if (k == 0) cout << str << endl;
	else cout << -1 << endl;
	return 0;
}
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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	if (l == 1 && r == n)
	{
		puts("0");
		return 0;
	}
	if (l == 1)
	{
		cout << abs(pos - r) + 1 << endl;
		return 0;
	}
	if (r == n)
	{
		cout << abs(pos - l) + 1 << endl;
		return 0;
	}
	cout << r - l + 1 + min(abs(r - pos), abs(l - pos)) + 1 << endl;
	
	return 0;
}
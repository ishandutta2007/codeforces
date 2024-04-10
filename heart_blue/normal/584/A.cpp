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
const int N = 1e4 + 10;
void solve(int n, int t)
{
	if (n == 1)
	{
		if (t == 10) t = -1;
		cout << t << endl;
		return;
	}
	string str = "1" + string(n - 1, '0');
	int r = 0;
	for (auto &c : str)
	{
		r = r * 10 + c - '0';
		r %= t;
	}
	str[n - 1] += (t - r) % t;
	cout << str << endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t;
	cin >> n >> t;
	solve(n, t);
	return 0;
}
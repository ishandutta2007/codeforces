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
const int N = 3e3 + 10;
int a[N];
int b[N];
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k, a, b;
	cin >> k >> a >> b;
	string str;
	cin >> str;
	int n = str.length();
	int l = n / k;
	int r = n / k;
	if (n % k) r++;
	if (l < a || r > b) puts("No solution"), exit(0);
	int cur = 0;
	int len = l;
	int rest = n % k;
	for (int i = 0; i < k; i++)
	{
		cout << str.substr(cur, len + (rest > 0)) << endl;
		cur += len + (rest > 0);
		rest--;
	}
	return 0;
}
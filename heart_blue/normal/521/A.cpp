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
int a[N];
LL powmod(LL a, LL b, LL mod = INF)
{
	LL o = a;
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret*o %INF;
		o = o*o%INF;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (auto &c : str) a[c]++;
	int maxv = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (maxv == a[i]) cnt++;
		else if (maxv < a[i]) maxv = a[i], cnt = 1;
	}
	cout << powmod(cnt, n) << endl;
	return 0;
}
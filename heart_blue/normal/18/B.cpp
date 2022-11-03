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
const int N = 1e6+10;
int a[N];
int b[N];
vector<int> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, d, m, l;
	cin >> n >> d >> m >> l;
	MEM(a, 0);
	LL tot = 0;
	LL len = (n - 1)*m + l;
	while (1)
	{
		LL o = (l - tot%m) / d + 1;
		tot += o*d;
		if (tot > len) break;
		if (tot % m > l) break;
	}
	cout << tot << endl;
	return 0;
}
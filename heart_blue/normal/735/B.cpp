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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL sum1 = 0, sum2 = 0;
	int n, n1, n2;
	cin >> n >> n1 >> n2;
	vector<int> a(n);
	if (n1 > n2) swap(n1, n2);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < n1; i++) sum1 += a[i];
	for (int i = n1; i < n1 + n2; i++) sum2 += a[i];
	printf("%.15f\n", sum1*1.0 / n1 + sum2*1.0 / n2);
	return 0;
}
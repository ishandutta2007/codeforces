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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> x(n), y(n), a(n), b(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	cout << x[0] + a[0] << ' ' << y[0] + b[0] << endl;

	return 0;
}
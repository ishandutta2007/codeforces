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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ans = 1;
	int n, k;
	cin >> n >> k;
	n /= k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int o = 1;
	while (--k) o *= 10;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		LL t = (o * 10 - 1) / a[i] + 1;
		t -= (o*(x + 1) - 1) / a[i] + 1;
		if(x > 0) t += (o*x - 1) / a[i] + 1;
		ans = ans*t%INF;
	}
	cout << ans << endl;
	return 0;
}
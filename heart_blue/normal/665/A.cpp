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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, ta, b, tb;
	scanf("%d%d%d%d", &a, &ta, &b, &tb);
	int h, m;
	scanf("%d:%d", &h, &m);
	int l = h * 60 + m;
	int r = l + ta;
	int cur;
	int ans = 0;
	for (cur = 300; cur <= l; cur += b)
	{
		if (cur + tb > l) 
			ans++;
	}
	for (cur = cur; cur < min(1440, r); cur += b) ans++;
	cout << ans << endl;
	return 0;
}
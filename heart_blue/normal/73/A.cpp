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

const int INF = 1e9 + 7;
const int N = 2e5 + 1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	LL ans = 1;
	int d;
	d = min(a - 1, k / 3);
	ans *= d + 1;
	k -= d;
	d = min(b - 1, k / 2);
	ans *= d + 1;
	k -= d;
	d = min(c - 1, k);
	ans *= d + 1;
	cout << ans << endl;
	return 0;
}
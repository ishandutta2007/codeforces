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
const int N = 1e5 + 10;
const double eps = 1e-11;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	LL r;
	LL a, b, c, d;
	cin >> r >> a >> b >> c >> d;
	r *= 2;
	LL dx = a - c;
	LL dy = b - d;
	LL dis = dx*dx + dy*dy;
	r = r*r;
	double ans = sqrt(dis*1.0 / r);
	cout << int(floor(ans - eps) + 1) << endl;
	
	return 0;
}
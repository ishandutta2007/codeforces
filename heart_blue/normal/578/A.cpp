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
const int N = 1e5 + 10;

map<LL, LL> ml;
void addWeight(LL x, LL w)
{
	ml[x] += w;
}
LL getWeight(LL x)
{
	if (ml.count(x)) return ml[x];
	else return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b;
	cin >> a >> b;
	a + b;
	if (a < b)
	{
		cout << -1 << endl;
	}
	else
	{
		LL sum = a + b;
		printf("%.15f\n", sum / (2.0*(sum / (2 * b))));
	}
	return 0;
}
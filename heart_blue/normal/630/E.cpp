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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
int a[N];
int check(int o)
{
	if (o & 1) return a[o] < a[o - 1] && a[o] < a[o + 1];
	else return a[o] > a[o - 1] && a[o] > a[o + 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout <<((y2-y1)/2+1)*(x2-x1+1)-(x2-x1)/2<<endl;
	return 0;
}
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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, vb, vs;
	cin >> n >> vb >> vs;
	int key = -1;
	for (int i = 0; i < n; i++) cin >> a[i];
	LL x, y;
	cin >> x >> y;
	pair<double, double> minv = { 1e15,1e15 };
	for (int i = 1; i < n; i++)
	{
		LL dx = a[i] - x;
		double d = sqrt(dx*dx + y*y);
		double t = a[i] * 1.0 / vb + d / vs;
		if (minv > make_pair(t,d))
		{
			minv = { t,d };
			key = i + 1;
		}
	}
	cout << key << endl;
	return 0;
}
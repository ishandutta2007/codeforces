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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double pi = acos(0.0) * 2;
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v)
	{
		cin >> x;
		x *= x;
	}
	sort(v.rbegin(), v.rend());
	int total = v[0];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i & 1) sum -= v[i];
		else sum += v[i];
	}
	printf("%.15f\n", sum * pi);
	return 0;
}
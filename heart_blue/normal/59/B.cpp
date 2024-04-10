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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, sum = 0;
	int minv = INF;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sum += x;
		if (x & 1) minv = min(minv, x);
	}
	if (sum & 1) cout << sum << endl;
	else if (minv < INF) cout << sum - minv << endl;
	else cout << 0 << endl;
	return 0;
}
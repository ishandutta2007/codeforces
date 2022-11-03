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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a[6] = { n >> 5 & 1,n >> 4 & 1,n >> 3 & 1,n >> 2 & 1,n >> 1 & 1,n & 1 };
	int b[6] = { a[0],a[5],a[3],a[2],a[4],a[1] };
	int ans = 0;
	for (int i = 0; i < 6; i++)
		ans = ans << 1 | b[i];
	cout << ans << endl;
	return 0;
}
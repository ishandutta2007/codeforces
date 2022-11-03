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
int L[N], R[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, a;
	cin >> n >> l >> a;
	for (int i = 1; i <= n; i++)
	{
		cin >> L[i] >> R[i];
		R[i] += L[i];
	}
	L[0] = R[0] = 0;
	L[n + 1] = R[n + 1] = l;
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans += (L[i + 1] - R[i]) / a;
	}
	cout << ans << endl;
	return 0;
}
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
const LL INF = 1e9 + 1;
const int N = 3e3 + 10;
int a[N];
int main()
{
	// freopen("input.txt","r",stdin);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	int s, t;
	cin >> s >> t;
	int ans = 0;
	if (s > t) swap(s, t);
	for (int i = s; i < t; i++) ans += a[i];
	cout << min(ans, sum - ans);
	return 0;
}
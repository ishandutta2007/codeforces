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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = a[n] - a[1] + 1;
	vector<int> v;
	for (int i = 2; i <= n; i++) v.push_back(a[i] - a[i - 1] - 1);
	sort(v.begin(), v.end());
	for (int i = 1; i < k && !v.empty(); i++)
	{
		ans -= v.back();
		v.pop_back();
	}
	cout << ans << endl;
	return 0;
}
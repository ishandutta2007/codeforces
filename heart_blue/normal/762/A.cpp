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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	cin >> n >> k;
	vector<LL> v;
	for (LL i = 1; i * i <= n; i++)
	{
		if (n%i != 0) continue;
		v.push_back(i);
		if (i*i != n) v.push_back(n / i);
	}
	sort(v.begin(), v.end());
	if (k > v.size()) cout << -1 << endl;
	else cout << v[k - 1] << endl;
	return 0;
}
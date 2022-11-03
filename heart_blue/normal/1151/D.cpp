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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ans = 0;
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		ans += -a + 1LL * b * n;
		v.push_back(a - b);
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++)
	{
		ans += v[i] * (i + 1LL);
	}
	cout << ans << endl;
	return 0;
}
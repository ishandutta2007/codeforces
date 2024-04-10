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
#include <iterator>
#include <complex>
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
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for (int i = 1; !v.empty(); i++)
	{
		while (!v.empty() && v.back() < i)
		{
			v.pop_back();
		}
		if (!v.empty() && v.back() >= i)
		{
			v.pop_back();
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
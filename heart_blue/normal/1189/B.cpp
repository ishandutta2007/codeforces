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
const int N = 5e3 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n), ans(n);
	for (auto& x : v) cin >> x;
	sort(v.rbegin(), v.rend());
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i += 2)
	{
		if (i == n - 1) ans[l] = v[i];
		else ans[l] = v[i], ans[r] = v[i + 1];
		l++, r--;
	}
	for (int i = 0; i < v.size(); i++)
	{
		int l = (i + n - 1) % n;
		int r = (i + 1) % n;
		if (ans[l] + ans[r] <= ans[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (auto& x : ans) cout << x << ' ';
	return 0;
}
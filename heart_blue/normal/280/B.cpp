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
const int N = 2e3 + 10;
int solve(vector<int> &v)
{
	reverse(v.begin(), v.end());
	stack<int> s;
	int ans = 0;
	for (auto &x : v)
	{
		while (!s.empty() && s.top() < x) s.pop();
		if (!s.empty()) ans = max(ans, s.top() ^ x);
		s.push(x);
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	//sort(v.begin(), v.end());
	cout << max(solve(v), solve(v)) << endl;
	return 0;
}
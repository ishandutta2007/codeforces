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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v1, v2;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x & 1) v1.push_back(x);
		else v2.push_back(x);
	}
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.begin(), v2.end());
	while (!v1.empty() && !v2.empty()) v1.pop_back(), v2.pop_back();
	if (v1.size() < v2.size()) swap(v1, v2);
	if (!v1.empty()) v1.pop_back();
	LL ans = 0;
	for (auto &x : v1) ans += x;
	cout << ans << endl;
	return 0;
}
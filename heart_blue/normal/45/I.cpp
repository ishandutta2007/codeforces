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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cnt = 0;
	vector<int> v1, v2;
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v) 
	{ 
		cin >> x;
		if (x > 0) v1.push_back(x);
		else if (x < 0) v2.push_back(x);
		else cnt++;
	}
	if (n == 1) cout << v[0] << endl, exit(0);
	vector<int> ans = v1;
	if (!v2.empty())
	{
		sort(v2.begin(), v2.end());
		if (v2.size() & 1) v2.pop_back();
		for (auto& x : v2)
			ans.push_back(x);
	}
	if (cnt && ans.empty()) ans.push_back(0);
	for (auto& x : ans) cout << x << ' ';
	return 0;
}
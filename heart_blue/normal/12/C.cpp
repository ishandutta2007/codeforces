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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<string, int> ms;
	int n, m;
	cin >> n >> m;
	vector<int> price(n);
	for (auto &x : price) cin >> x;
	while (m--)
	{
		string str;
		cin >> str;
		ms[str]++;
	}
	vector<int> v;
	for (auto &p : ms)
	{
		v.push_back(p.second);
	}
	sort(price.begin(), price.end());
	sort(v.rbegin(), v.rend());
	int ans1 = 0;
	for (int i = 0; i < v.size(); i++) ans1 += v[i] * price[i];
	int ans2 = 0;
	reverse(price.begin(), price.end());
	for (int i = 0; i < v.size(); i++) ans2 += v[i] * price[i];
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
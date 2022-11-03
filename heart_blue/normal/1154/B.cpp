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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		mc[x]++;
	}
	vector<int> v;
	for (auto &p : mc) v.push_back(p.first);
	if (v.size() > 3)
	{
		puts("-1");
		return 0;
	}
	if (v.size() < 3)
	{
		int ans = v.back() - v.front();
		if (ans % 2 == 0) ans /= 2;
		cout << ans << endl;
		return 0;
	}
	if (v[1] - v[0] == v[2] - v[1]) cout << v[2] - v[1] << endl;
	else cout << -1 << endl;
	return 0;
}
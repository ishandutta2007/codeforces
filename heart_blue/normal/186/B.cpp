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
const int N = 1e5 + 10;
vector<pair<int,int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t1, t2, k;
	cin >> n >> t1 >> t2 >> k;
	k = 100 - k;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		int maxv = max(t1*a*k + t2*b*100, t1*b*k + t2*a*100);
		vp.push_back({maxv,i});
	}
	sort(vp.begin(), vp.end(), [](pair<int, int> &p1, pair<int, int> &p2)->bool
	{
		if (p1.first != p2.first) return p1.first > p2.first;
		return p1.second < p2.second;
	});
	for (auto &p : vp)
	{
		printf("%d %d.%02d\n", p.second, p.first / 100, p.first % 100);
	}
	return 0;
}
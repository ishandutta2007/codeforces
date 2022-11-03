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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5+ 10;
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	vp.resize(n);
	for (auto &p : vp)
	{
		cin >> p.first >> p.second;
	}
	sort(vp.begin(), vp.end());
	LL ans = 0;
	LL sum = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		while (k < n && vp[k].first - vp[i].first < d)
		{
			sum += vp[k].second;
			ans = max(ans, sum);
			k++;
		}
		sum -= vp[i].second;
	}
	cout << ans << endl;
	
	return 0;
}
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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> v1, v2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, sum;
		cin >> x >> sum;
		if (x < 0) v1.push_back({ -x,sum });
		else v2.push_back({ x,sum });
	}
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.begin(), v2.end());
	n = min(v1.size(), v2.size()) + 1;
	int ans = 0;
	for (int i = 0; i < min((int)v1.size(), n); i++) ans += v1[i].second;
	for (int i = 0; i < min((int)v2.size(), n); i++) ans += v2[i].second;
	cout << ans << endl;
	return 0;
}
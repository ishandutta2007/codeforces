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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int n, a, b;
	cin >> n;
	int cnt = 1;
	int ans = 0;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (b == 0) v.push_back(a);
		else ans += a, cnt += b - 1;
	}
	sort(v.rbegin(), v.rend());
	cnt = min(cnt, (int)v.size());
	for (int i = 0; i < cnt;i++) ans += v[i];
	cout << ans << endl;
	return 0;
}
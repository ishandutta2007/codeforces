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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
vector<pair<int,int>> v;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back({ x,i });
	}
	sort(v.begin(), v.end());
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
	{
		ans[v[i].second] = a[i];
	}
	for (int i = 0; i < n; i++)cout << ans[i] << ' ';
	return 0;
}
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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 2; i < N; i++)
	{
		for (int j = i; j < N; j += i)
		{
			v[j].push_back(i);
		}
	}
	MEM(a, 0);
	int ans = 1;
	int n, x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		int maxv = 0;
		for (auto d : v[x]) maxv = max(maxv, a[d]);
		maxv++;
		for (auto d : v[x]) a[d] = maxv;
		ans = max(maxv, ans);
	}
	cout << ans << endl;
	return 0;
}
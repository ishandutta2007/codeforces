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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	LL sum = 0;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		if (k == 0) break;
		if (v[i] < 0)
		{
			v[i] = -v[i];
			k--;
		}
	}
	if (k % 2 == 1)
	{
		sort(v.begin(), v.end());
		v[0] = -v[0];
	}
	for (auto &x : v) sum += x;
	cout << sum << endl;
	return 0;
}
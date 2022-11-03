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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<LL> v;
	for (int i = 2; i < 63; i++)
	{
		LL o = 1LL << i;
		o--;
		for (int j = 0; j < i - 1; j++)
		{
			v.push_back(o ^ (1LL << j));
		}
	}
	sort(v.begin(), v.end());
	LL l, r;
	cin >> l >> r;
	int ans = 0;
	for (auto &x : v)
	{
		if (x > r) break;
		if (x >= l) ans++;
	}
	cout << ans << endl;
	return 0;
}
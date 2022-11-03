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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int rest = a[1];
	vector<int> ans;
	ans.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		if (a[i] * 2 <= a[1])
			ans.push_back(i), rest += a[i];
	}
	if (rest * 2 <= sum) ans.clear();
	cout << ans.size() << endl;
	for (auto& x : ans) cout << x << ' ';
	return 0;
}
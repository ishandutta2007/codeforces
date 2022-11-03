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
const int N = 3e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i > 0; i--) a[i] -= a[i - 1];
	vector<int> v;
	for (int len = 1; len <= n; len++)
	{
		int flag = 1;
		for (int i = 1; i + len <= n; i++)
		{
			if (a[i] != a[i + len])
			{
				flag = 0;
				break;
			}
		}
		if (flag) v.push_back(len);
	}
	cout << v.size() << '\n';
	for (auto &x : v) cout << x << ' ';
	return 0;
}
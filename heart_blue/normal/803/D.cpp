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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	getline(cin, str);
	for (auto& c : str)
	{
		if (c == '-') c = ' ';
	}
	stringstream sin(str);
	vector<int> v;
	while (sin >> str)
	{
		v.emplace_back(str.length() + 1);
	}
	v.back()--;
	int l = 1, r = INF;
	int ans = INF;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int sum = 0;
		int tot = 1;
		for (auto& x : v)
		{
			if (x > mid)
			{
				tot = INF;
				break;
			}
			if (sum + x > mid) sum = 0, tot++;
			sum += x;
		}
		if (tot <= n) ans = mid, r = mid - 1;
		else l = mid+ 1;
	}
	printf("%d\n", ans);
	return 0;
}
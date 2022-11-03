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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
	{
		auto &p = v[i - 1];
		cin >> p.first;
		p.second = i;
	}
	sort(v.begin(), v.end());
	int sum1 = 0, sum2 = 0;
	for (auto &p : v)
	{
		int x, o;
		tie(x, o) = p;
		if (v1.size() < v2.size()) v1.push_back(o), sum1 += x;
		else if (v1.size() > v2.size()) v2.push_back(o), sum2 += x;
		else
		{
			if (sum1 < sum2) v1.push_back(o), sum1 += x;
			else v2.push_back(o), sum2 += x;
		}
	}
	cout << v1.size() << endl;
	for (auto &x : v1) cout << x << ' ';
	cout << endl << v2.size() << endl;
	for (auto &x : v2) cout << x << ' ';
	return 0;
}
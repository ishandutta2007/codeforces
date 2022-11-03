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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
vector<int> v[2];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	v[0].resize(n);
	v[1].resize(n);
	for (auto &x : v[0]) cin >> x;
	for (auto &y : v[1]) cin >> y;
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	LL sum = 0;
	int flag = 1;
	int o = 0;
	while (!(v[0].empty() && v[1].empty()))
	{
		if (v[o].empty())
		{
			v[o ^ 1].pop_back();
		}
		else if (v[o ^ 1].empty())
		{
			sum += flag * v[o].back();
			v[o].pop_back();
		}
		else
		{
			if (v[o].back() >= v[o ^ 1].back())
			{
				sum += flag * v[o].back();
				v[o].pop_back();
			}
			else
			{
				v[o ^ 1].pop_back();
			}
		}
		o ^= 1;
		flag = -flag;
	}
	cout << sum << '\n';
	return 0;
}
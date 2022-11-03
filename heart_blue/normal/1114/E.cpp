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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int maxv = 0;
	int l = 0, r = 1e9;
	int rest = 60;
	while (l <= r)
	{
		rest--;
		int mid = (l + r) / 2;
		cout << "> " << mid << endl;
		int ret;
		cin >> ret;
		if (ret) maxv = mid + 1, l = mid + 1;
		else r = mid - 1;
	}
	vector<int> v;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	while (rest--)
	{
		cout << "? " << rng() % n + 1 << endl;
		int x;
		cin >> x;
		if (count(v.begin(), v.end(), x) == 0)
			v.push_back(x);
	}
	int g = 0;
	for (int i = 1; i < v.size(); i++)
	{
		g = gcd(g, abs(v[i] - v[i - 1]));
	}
	int minv = maxv - g * (n - 1);
	cout << "! " << minv << ' ' << g << endl;
	return 0;
}
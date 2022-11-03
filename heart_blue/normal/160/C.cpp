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
	map<int, LL> m;
	LL k = 0;
	int n;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &x : v)
	{
		cin >> x;
		m[x]++;
	}
	sort(v.begin(), v.end());
	k--;
	for (auto &p : m)
	{
		if (p.second * n <= k)
		{
			k -= p.second*n;
		}
		else
		{
			k /= p.second;
			cout << p.first << ' ' << v[k] << endl;
			break;
		}
	}
	return 0;
}
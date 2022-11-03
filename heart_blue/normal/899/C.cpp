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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	LL tot = 1LL * n*(n + 1) / 2;
	if (tot & 1) cout << 1 << endl;
	else cout << 0 << endl;
	tot /= 2;
	for (int i = n; i >= 1; i--)
	{
		if (tot <= i)
		{
			v.push_back(tot);
			break;
		}
		else v.push_back(i), tot -= i;
	}
	cout << v.size();
	for (auto &x : v) cout << ' ' << x;

	return 0;
}
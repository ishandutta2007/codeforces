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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v;
	LL tot = 0;
	for (int i = 0; i < n; i++)
	{
		int k, l;
		cin >> k >> l;
		tot += min(k, l);
		if (k >= l) v.push_back(0);
		else v.push_back(min(k, l - k));
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < m; i++) tot += v[i];
	cout << tot << endl;
	return 0;
}
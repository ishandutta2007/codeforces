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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (auto &x : v) cin >> x;
	if(!v.empty()) sort(v.begin(), v.end());
	int flag = 0;
	if(!v.empty()) flag = (v.back() == n || v.front() == 1);
	for (int i = 2; i < m; i++)
	{
		if (v[i] - v[i - 2] == 2) flag = 1;
	}
	if (flag) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}
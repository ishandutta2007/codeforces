#pragma comment(linker, "/STACK:102400000,102400000") 
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
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	map<int, int> mc;
	int cnt = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (mc.count(v[i])) v[i] = 0;
		else mc[v[i]] = 1;
	}
	cout << mc.size() << endl;
	for (auto &x : v) if (x != 0) cout << x << ' ';
	return 0;
}
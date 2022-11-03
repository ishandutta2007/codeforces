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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
pair<int, int> ask(vector<int>& v, int x = 0, int y = 0)
{
	cout << "?";
	for (auto& a : v)
	{
		if (a == x) continue;
		if (a == y) continue;
		cout << " " << a;
	}
	cout << endl;
	int a, val;
	cin >> a >> val;
	return make_pair(a, val);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	// 9 0 1 2
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= k + 1; i++) v.push_back(i);
	int val1, val2;
	int k1, k2;
	tie(k1, val1) = ask(v, k + 1);
	tie(k2, val2) = ask(v, k1);
	int cnt = 0;
	for (int i = 1; i <= k + 1; i++)
	{
		if (i == k1) continue;
		if (i == k2) continue;
		int x = ask(v, i).second;
		if (x == max(val1, val2)) cnt++;
	}
	cout << "! " << cnt + 1 << endl;
	return 0;
}
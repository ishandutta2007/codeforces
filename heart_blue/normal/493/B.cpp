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
const int N = 2e2 + 10;
vector<int> v1, v2;
bool check(int x)
{
	LL sum1 = 0, sum2 = 0;
	for (auto &x : v1) sum1 += x;
	for (auto &x : v2) sum2 += x;
	if (sum1 != sum2) return sum1 > sum2;
	int n = max(v1.size(), v2.size());
	while (v1.size() < n) v1.push_back(0);
	while (v2.size() < n) v2.push_back(0);
	for (int i = 0; i < n; i++)
	{
		if (v1[i] > v2[i]) return true;
		if (v1[i] < v2[i]) return false;
	}
	return x > 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > 0) v1.push_back(x);
		else v2.push_back(-x);
	}
	if (check(x)) cout << "first" << endl;
	else cout << "second" << endl;
	return 0;
}
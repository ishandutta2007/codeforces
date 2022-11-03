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
const int N = 5e2 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	MEM(b, 0);
	string s1, s2;
	cin >> s1 >> s2;
	for (auto &c : s1) a[c]++;
	for (auto &c : s2) b[c]++;
	int ans1 = 0, ans2 = 0;
	for (int i = 'a'; i <= 'z'; i++)
	{
		int o = min(a[i], b[i]) + min(a[i - 32], b[i - 32]);
		ans1 += o;
		ans2 += min(a[i] + a[i - 32], b[i] + b[i - 32]) - o;
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
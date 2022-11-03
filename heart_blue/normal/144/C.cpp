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
const int N = 2e2 + 10;
int a[N], b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	MEM(a, 0);
	MEM(b, 0);
	for (auto &c : s2) a[c]++;
	int n = s1.length(), m = s2.length();
	int &cnt = b['?'];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		b[s1[i]]++;
		if (i >= m) b[s1[i - m]]--;
		int tot = 0;
		for (int j = 'a'; j <= 'z'; j++) tot += max(0, a[j] - b[j]);
		if (tot <= cnt) ans++;
	}
	cout << ans << endl;
	return 0;
}
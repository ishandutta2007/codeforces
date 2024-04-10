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
const int N = 1e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> m;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		m[x] = 1;
	}
	if (m.size() > 3) cout << "NO" << endl;
	else if (m.size() < 3) cout << "YES" << endl;
	else
	{
		int a[3];
		int o = 0;
		for (auto &p : m) a[o++] = p.first;
		if (a[1] * 2 == a[0] + a[2]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
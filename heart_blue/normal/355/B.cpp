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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3+10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	int n[2];
	cin >> n[0] >> n[1];
	int ans = 0;
	for (int i = 0; i < 2; i++)
	{
		int m = n[i];
		MEM(a, 0);
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			sum += min(x*c1, c2);
		}
		ans += min(sum, c3);
	}
	ans = min(ans, c4);
	cout << ans << endl;
	return 0;
}
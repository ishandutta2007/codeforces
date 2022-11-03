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
const int N = 1e5 + 10;
int w[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s1, s2;
	string rs1, rs2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];
	cin >> s1;
	rs1 = s1;
	reverse(rs1.begin(), rs1.end());
	LL a = 0;
	LL b = w[0];
	for (int i = 1; i < n; i++)
	{
		LL x = INF*INF;
		LL y = INF*INF;
		cin >> s2;
		rs2 = s2;
		reverse(rs2.begin(), rs2.end());
		if (s2 >= s1) x = min(x, a);
		if (s2 >= rs1) x = min(x, b);
		if (rs2 >= s1) y = min(y, a + w[i]);
		if (rs2 >= rs1) y = min(y, b + w[i]);
		if (x == INF*INF && y == INF*INF)
		{
			cout << -1 << endl;
			return 0;
		}
		s1 = s2;
		rs1 = rs2;
		a = x;
		b = y;
	}
	cout << min(a, b) << endl;

	return 0;
}
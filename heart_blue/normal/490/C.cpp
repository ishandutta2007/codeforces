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
const int N = 1e6 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n, m;
	cin >> n >> m;
	int l = s.length();
	LL r = 0;
	MEM(flag, 0);
	for (int i = 0; i < l; i++)
	{
		r = r * 10 + s[i] - '0';
		r %= n;
		if (r == 0) flag[i + 1] = 1;
	}
	int f = 0;
	r = 0;
	LL o = 1;
	for (int i = l - 1; i >= 0; i--)
	{
		r = r + o*(s[i] - '0');
		r %= m;
		o = o * 10 % m;
		if (s[i] > '0') f = 1;
		if (f == 0) continue;
		if (r == 0 && flag[i])
		{
			cout << "YES" << endl;
			cout << s.substr(0, i) << endl;
			cout << s.substr(i) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
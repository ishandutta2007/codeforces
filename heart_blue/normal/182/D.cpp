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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
bool check(string &s, int l)
{
	for (int i = 0; i + l < s.length(); i++)
	{
		if (s[i] != s[i + l]) return false;
	}
	return true;
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	int g = gcd(n, m);
	int ans = 0;
	for (int i = 1; i <= g; i++)
	{
		if (g%i) continue;
		if (s1.substr(0,i) != s2.substr(0,i)) break;
		if (check(s1, i) && check(s2, i)) ans++;
	}
	cout << ans << endl;
	return 0;
}
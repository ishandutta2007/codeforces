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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1;
	string s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	int p = -1;
	int k1 = m, k2 = 0;
	for (int i = 0; i < n; i++)
	{
		p++;
		while (p < m && s1[i] != s2[p]) p++;
		if (i == n - 1) k1 = p;
	}
	p = m;
	for (int i = n - 1; i >= 0; i--)
	{
		p--;
		while (p >= 0 && s1[i] != s2[p]) p--;
		if (i == 0) k2 = p;
	}
	cout << max(0, k2 - k1) << endl;
	return 0;
}
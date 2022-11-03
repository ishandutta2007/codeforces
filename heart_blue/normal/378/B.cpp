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
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	int n;
	cin >> n;
	s1 = string(n, '0');
	s2 = string(n, '0');
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	int l = 0, r = 0;
	int cnt = 0;
	while (cnt < n && l < n && r < n)
	{
		if (a[l] < b[r]) s1[l++] = '1';
		else s2[r++] = '1';
		cnt++;
	}
	for (int i = 1; i * 2 <= n; i++) s1[i-1] = s2[i-1] = '1';
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
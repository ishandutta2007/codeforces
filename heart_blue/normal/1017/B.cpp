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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a[4] = { 0,0,0,0 };
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		int o1 = s1[i] - '0';
		int o2 = s2[i] - '0';
		a[o1 * 2 + o2]++;
	}
	cout << a[0] * a[2] + a[0] * a[3] + a[1] * a[2] << endl;
	return 0;
}
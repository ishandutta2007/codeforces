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
const int N = 1e7 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[10] = { 0 };
	int b[32] = { 0 };
	int cur = 5;
	for (int i = 1; i <= 366; i++)
	{
		a[cur]++;
		cur++;
		if (cur > 7) cur = 1;
	}
	for (int i = 1; i <= 29; i++) b[i] = 12;
	b[30] = 11;
	b[31] = 7;
	int n;
	string str;
	cin >> n >> str >> str;
	if (str == "week") cout << a[n] << endl;
	else cout << b[n] << endl;
	return 0;
}
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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6;
int a[N];
int ans[N];
int k = 0;
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j < N; j += i)
			a[j] = 1;
	}
	for (int i = 10; i < N; i++)
	{
		if (a[i]) continue;
		string s = to_string(i);
		reverse(s.begin(), s.end());
		int x = stoi(s);
		if (i == x) continue;
		if (a[x] == 0)
			ans[++k] = i;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	cout << ans[n] << endl;
	return 0;
}
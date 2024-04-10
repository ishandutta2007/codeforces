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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int pos[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a[] = { 0, 4,8,15,16,23,42 };
	for (int i = 1; i <= 6; i++) pos[a[i]] = i;
	ans[0] = INF;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x = pos[x];
		if (ans[x - 1]) ans[x - 1]--, ans[x]++;
	}
	cout << n - ans[6] * 6 << endl;
	return 0;
}
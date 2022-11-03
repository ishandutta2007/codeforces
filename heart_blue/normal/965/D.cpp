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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l;
	cin >> n >> l;
	for (int i = 1; i < n; i++) cin >> a[i];
	a[n] = INF;
	b[0] = INF;
	int ptr = 0;
	for (int i = 1; i <= n; i++)
	{
		while (ptr + l < i) ptr++;
		while (ptr < i && a[i] > b[i])
		{
			int o = min(b[ptr], a[i] - b[i]);
			b[ptr] -= o;
			b[i] += o;
			if (b[ptr] == 0) ptr++;
		}
	}
	cout << b[n] << endl;
	return 0;
}
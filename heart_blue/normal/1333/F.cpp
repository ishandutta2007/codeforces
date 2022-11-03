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
const int N = 5e5 + 10;
int a[N];
int cnt[N];
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + i; j <= n; j += i)
			a[j] = i;
	}
	for (int i = 2; i <= n; i++) cnt[a[i]]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	init(n);
	for (int i = 1; i <= n; i++)
		while (cnt[i]--) printf("%d ", i);
	return 0;
}
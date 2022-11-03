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
const int N = 4e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ptr = 0;
	int key = 0;
	map<int, int> ms;
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		while (ptr < n && ms[key] < k)
		{
			key = a[ptr++];
			ms[key]++;
		}
		if (ms[key] >= k)
		{
			ans += n - (ptr - 1);
		}
		ms[a[i]]--;
	}
	cout << ans << endl;
	return 0;
}
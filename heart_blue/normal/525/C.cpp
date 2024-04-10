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
const int N = 1e6 + 10;
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int n;
	cin >> n;
	MEM(flag, 0);
	while (n--)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = N - 1; i > 0; i--)
	{
		if (a[i] % 2 == 1)
		{
			if (a[i] > 1) a[i]--, a[i - 1]++, flag[i - 1] = 1;
			else if (flag[i] == 0) a[i]--, a[i - 1]++, flag[i - 1] = 1;
		}
		a[i] /= 2;
		while (a[i]--) v.push_back(i);
	}
	LL ans = 0;
	for (int i = 1; i < v.size(); i += 2)
	{
		ans += (LL)v[i] * v[i - 1];
	}
	cout << ans << endl;

	return 0;
}
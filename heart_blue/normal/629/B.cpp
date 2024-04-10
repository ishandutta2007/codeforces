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
const int N = 4e4 + 10;


int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	MEM(b, 0);
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		char c;
		cin >> c >> x >> y;
		if (c == 'F')
		{
			a[x]++;
			a[y + 1]--;
		}
		else
		{
			b[x]++;
			b[y + 1]--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 366; i++)
	{
		a[i] += a[i - 1];
		b[i] += b[i - 1];
		ans = max(min(a[i],b[i])*2, ans);
	}
	cout << ans << endl;
	return 0;
}
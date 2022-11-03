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
const int N = 1e6 + 10;
const LL INF = 1e9 + 7;
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = a; i <= b; i++)
	{
		sum[i + b]++;
		sum[i + c + 1]--;
	}
	for (int i = 1; i < N; i++)
		sum[i] += sum[i - 1];
	for (int i = 1; i < N; i++)
		sum[i] += sum[i - 1];
	LL ans = 0;
	for (int i = c; i <= d; i++)
	{
		ans += sum[N - 1] - sum[i];
	}
	cout << ans << endl;
	return 0;
}
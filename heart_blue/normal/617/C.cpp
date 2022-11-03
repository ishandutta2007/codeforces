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
const int N = 2e3 + 10;
int flag[N];
LL x[N];
LL y[N];
LL dis(int i, int j)
{
	LL dx = x[i] - x[j];
	LL dy = y[i] - y[j];
	return dx*dx + dy*dy;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	n += 2;
	LL minx = INF*INF;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
	{
		LL r1 = dis(0,i);
		LL r2 = 0;
		for (int j = 0; j < n; j++)
		{
			if (dis(0,j) > r1)
			{
				r2 = max(r2, dis(1,j));
			}
		}
		minx = min(minx, r1 + r2);
	}
	cout << minx << endl;
	return 0;
}
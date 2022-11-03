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
const int N = 1e5 + 10;
int r[N];
int m[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tot = 720720;
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> m[i];
	for (int i = 0; i < n; i++) cin >> r[i];
	for (int i = 0; i < tot; i++)
	{
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (i%m[j] == r[j]) flag = 1;
		}
		ans += flag;
	}
	printf("%.15f\n", 1.0*ans / tot);
	return 0;
}
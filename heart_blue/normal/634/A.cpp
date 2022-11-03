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
const int N = 2e5 + 10;
int a[N];
int b[N];
vector<int> v1, v2;
int n;
void refrain(int a[], vector<int> &v)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 1) continue;
		v.push_back(a[i]);
		for (int j = 1; j < n; j++)
		{
			if (a[(i + j) % n])
				v.push_back(a[(i + j) % n]);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	refrain(a, v1);
	refrain(b, v2);
	if (v1 == v2) puts("YES");
	else puts("NO");
	return 0;
}
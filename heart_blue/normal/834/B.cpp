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
const int N = 1e6 + 10;
int a[N];
int b[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fill(a, a + N, N - 2);
	fill(b, b + N, N - 2);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		a[str[i]] = min(a[str[i]], i);
		b[str[i]] = i;
	}
	for (int i = 'A'; i <= 'Z'; i++)
	{
		sum[a[i]]++;
		sum[b[i] + 1]--;
	}
	for (int i = 1; i < n; i++)
	{
		sum[i] += sum[i - 1];
		if (sum[i] > k)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");

	return 0;
}
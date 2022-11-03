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
int cnt[N];
LL ans[N];
int p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	p[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p[i] = p[i - 1] << 1;
		if (p[i] >= INF) p[i] -= INF;
	}
	for (int i = 2; i < N; i++)
	{
		for (int j = i + i; j < N; j += i)
		{
			cnt[i] += cnt[j];
		}
	}
	LL res = 0;
	for (int i = N - 1; i > 1; i--)
	{
		if (cnt[i] == 0) continue;
		ans[i] = p[cnt[i] - 1] %INF*cnt[i] % INF;
		for (int j = i + i; j < N; j += i)
		{
			ans[i] -= ans[j];
			if (ans[i] < 0) ans[i] += INF;
		}
		res += i * ans[i] % INF;
		if (res >= INF) res -= INF;
	}
	cout << res << endl;
	return 0;
}
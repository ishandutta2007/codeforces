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
const LL INF = 1e9 + 9;
const int N = 2e2 + 10;
int cnt[N];
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		MEM(cnt, 0);
		for (auto& c : str)
			cnt[c]++;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		MEM(ans, -1);
		int tot = 0;
		int cur = 'z';
		while (1)
		{
			vector<int> v;
			for (int i = 0; i < n; i++)
			{
				if (ans[i] != -1) continue;
				int sum = 0;
				for (int j = 0; j < n; j++)
				{
					if (ans[j] == -1) continue;
					sum += abs(i - j);
				}
				if (sum == a[i])
					v.push_back(i);
			}
			while (cnt[cur] < v.size()) cur--;
			for (auto& x : v)
				ans[x] = cur;
			cur--;
			tot += v.size();
			if (tot == n) break;
		}
		for (int i = 0; i < n; i++)
			putchar(ans[i]);
		puts("");
	}
	return 0;
}
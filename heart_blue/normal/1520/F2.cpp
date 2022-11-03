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

int sum2[N];
const int M = 12;
int ask(int l, int r)
{
	printf("? %d %d", l, r);
	cout << endl;
	int val;
	cin >> val;
	return (r - l + 1) - val;
}
void init(int n, int flag = 0)
{
	if (flag) return;
	int l = 1, r = M;
	while (l <= n)
	{
		int len = min(r, n);
		sum2[r / M] = ask(l, len);
		l += M, r += M;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, ncase;
	cin >> n >> ncase;
	int flag = 0;
	while (ncase--)
	{
		int k;
		cin >> k;
		init(n, flag++);
		int l = 1, r = M;
		int pos = 1;
		while (l <= n)
		{
			pos = r / M;
			if (sum2[pos] >= k)
			{
				break;
			}
			else
			{
				k -= sum2[pos];
			}
			l += M, r += M;
		}
		r = min(r, n);
		int key = l - 1;
		int kl = l;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int tot = ask(kl, mid);
			if (tot >= k) key = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << "! " << key << endl;
		sum2[pos]--;
		assert(sum2[pos] >= 0);
	}
	return 0;
}
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
const int N = 5e3 + 10;
int v1[N];
int v2[N];
int p[N];
int b[N];
int flag[N];
int ask(int i, int j)
{
	cout << "? " << i << ' ' << j << endl;
	int ret;
	cin >> ret;
	return ret;
}
bool check(int a[], int n)
{
	fill(flag, flag + n, 0);
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= n) return false;
		if (flag[a[i]]) return false;
		flag[a[i]] = 1;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		v1[i] = ask(0, i);
		v2[i] = ask(i, 0);
	}
	int ans = 0;
	vector<int> key;
	for (int o = 0; o < n; o++)
	{
		p[0] = o;
		b[0] = o ^ v1[0];
		for (int i = 1; i < n; i++)
		{
			p[i] = v2[i] ^ b[0];
			b[i] = v1[i] ^ p[0];
		}
		if (!check(p, n) || !check(b, n)) continue;
		int ok = 1;
		for (int i = 0; i < n; i++)
		{
			if (p[b[i]] != i)
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			ans++;
			key = vector<int>(p, p + n);
		}
	}
	cout << "!\n";
	cout << ans << '\n';
	for (int i = 0; i < n; i++)
	{
		if (i) cout << ' ';
		cout << key[i];
	}
	cout << endl;

	return 0;
}
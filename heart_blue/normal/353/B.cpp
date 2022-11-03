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
const LL INF = 1e9 + 1;
const int N = 1e3 + 10;
int flag[100];
int a[2 * 100 + 10];
int b[100];
int c[210];
int main()
{
	int n;
	//freopen("input.txt","r",stdin);
	MEM(b, 0);
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	int s1 = 0;
	int s2 = 0;
	for (int i = 10; i <= 99; i++)
	{
		if (b[i] == 0) continue;
		if (b[i] == 1)
		{
			b[i] = -1;
			continue;
		}
		if (b[i] % 2 == 0)
		{
			flag[i] = 0;
			b[i] = 0;
			continue;
		}
		b[i] = 1;
	}
	int t = 0;
	for (int i = 10; i <= 99; i++)
	{
		if (b[i] == -1)
		{
			flag[i] = t;
			t ^= 1;
		}
	}
	for (int i = 10; i <= 99; i++)
	{
		if (b[i] == 1)
		{
			flag[i] = t;
			t ^= 1;
		}
	}
	for (int i = 0; i < n * 2; i++)
	{
		c[i] = flag[a[i]];
		flag[a[i]] ^= 1;
	}
	map<int, int> m;
	for (int i = 0; i < n * 2; i++)
	{
		if (c[i] == 1) continue;
		for (int j = 0; j < n * 2; j++)
		{
			if (c[j] == 0) continue;
			m[a[i] * 100 + a[j]] = 1;
		}
	}
	cout << m.size() << endl;
	for (int i = 0; i < n * 2; i++)
	{
		cout << c[i] + 1;
		if (i < n * 2 - 1) cout << ' ';
		else cout << endl;
	}
	return 0;
}
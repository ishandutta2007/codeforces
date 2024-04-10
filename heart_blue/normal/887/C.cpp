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
const int N = 2e2 + 10;
int n = 24;
int a[N];
int b[N];
int rt[] = { 0,3,1,4,2,17,18,19,20,10,12,9,11,5,6,7,8,21,22,23,24,13,14,15,16 };
int rot[] = { 0,3,1,4,2,17,18,7,8,9,10,11,12,5,6,15,16,21,22,19,20,13,14,23,24 };
int up[] = { 0,24,23,22,21,1,2,3,4,5,6,7,8,15,13,16,14,18,20,17,19,12,11,10,9 };

bool check()
{
	for (int i = 1; i <= n; i += 4)
	{
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i + 2] == a[i + 3])
		{
			continue;
		}
		else return false;
	}
	puts("YES");
	exit(0);
	return true;
}
void change(int r[])
{
	for (int i = 1; i <= n; i++)
	{
		b[r[i]] = a[i];
	}
	memcpy(a, b, sizeof(b));
	//for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	//cout << endl;
}
void check1()
{
	change(rot); check();
	change(rot), change(rot); check();
	change(rot);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i <= n; i++) cin >> a[i];
	check1();
	change(up); check1();
	change(up); check1();
	change(up); check1();
	change(up); change(rt); change(up); check1();
	change(up); change(up); check1();
	puts("NO");
	return 0;
}
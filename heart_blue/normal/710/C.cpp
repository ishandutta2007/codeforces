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
const int N = 1e2;
int a[N][N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) a[i][n / 2] = a[n / 2][i] = 1;
	int tot = n*n / 2 + 1;
	tot -= 2 * n - 1;
	tot /= 2;
	for (int i = 0; i < n / 2; i++)
	{
		int l = 0;
		int r = n - 1;
		while (l < r)
		{
			if (tot == 0) break;
			a[i][l] = a[i][r] = 1;
			a[n - i - 1][l] = a[n - i - 1][r] = 1;
			l++;
			r--;
			tot -= 2;
		}
	}
	int l = 1;
	int r = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j])
			{
				cout << l << ' ';
				l += 2;
			}
			else
			{
				cout << r << ' ';
				r += 2;
			}
		}
		cout << endl;
	}
	return 0;
}
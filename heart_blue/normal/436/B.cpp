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
const double eps = 1e-10;
const int N = 2010;
char c[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		for (int j = 1; j < n; j++)
		{
			if (j + j < n && c[j+j][i] == 'U') cnt++;
			if (i-j >= 0 && c[j][i-j] == 'R') cnt++;
			if (j+i < m && c[j][i + j] == 'L') cnt++;

		}
		if (i) cout << ' ';
		cout << cnt;
	}
	cout << endl;

	return 0;
}
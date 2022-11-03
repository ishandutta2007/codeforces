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
const int N = 2e6;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			for (int k = 0; k < n; k++)
			{
				if (j == k || k == i) continue;
				if (v[i] == v[j] + v[k])
				{
					cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
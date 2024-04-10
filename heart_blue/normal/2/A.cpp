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

const int INF = 1e9 + 3;
const int N = 2e3 + 1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<string> vs(n);
	vector<int> v(n);
	map<string, int> ms;
	for (int i = 0; i < n; i++) cin >> vs[i] >> v[i], ms[vs[i]] += v[i];
	int maxv = 0;
	for (auto & x : ms) maxv = max(maxv, x.second);
	map<string, int> ms2;
	for (int i = 0; i < n; i++)
	{
		ms2[vs[i]] += v[i];
		if (ms2[vs[i]] >= maxv && ms[vs[i]] == maxv)
		{
			cout << vs[i] << endl;
			return 0;
		}
	}
	return 0;
}
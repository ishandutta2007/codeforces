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

const int INF = 1e9 + 7;
const int N = 1e3 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs = { "chest", "biceps", "back" };
	int a[3] = { 0 };
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) cin >> x, a[i % 3] += x;
	int key = -1;
	int maxv = 0;
	for (int i = 0; i < 3; i++) if (a[i] > maxv) maxv = a[i], key = i;
	cout << vs[key] << endl;
	return 0;
}
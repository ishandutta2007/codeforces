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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	a[0] = 1;
	for (int i = 1; i < N; i++) a[i] = 4 * a[i - 1] % INF;
	b[1] = 3;
	for (int i = 2; i < N; i++) b[i] = (3 * b[i - 1] + a[i - 1]) % INF;
	for (int i = 1; i < N; i++)
	{
		a[i] -= b[i];
		if (a[i] < 0) a[i] += INF;
	}
	int n;
	cin >> n;
	cout << a[n] << endl;
	return 0;
}
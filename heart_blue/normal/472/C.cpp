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
const int N = 2e5 + 10;
int a[N];


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	
	vector<string> vs1, vs2;
	int n;
	cin >> n;
	vs1.resize(n+1);
	vs2.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> vs1[i] >> vs2[i];
	int pre = 0;
	int flag1, flag2;
	flag1 = flag2 = 1;
	for (int i = 1; i <= n; i++)
	{
		int f1, f2;
		int x;
		cin >> x;
		f1 = f2 = 0;
		if (flag1)
		{
			if (vs1[x] > vs1[pre]) f1 = 1;
			if (vs2[x] > vs1[pre]) f2 = 1;
		}
		if (flag2)
		{
			if (vs1[x] > vs2[pre]) f1 = 1;
			if (vs2[x] > vs2[pre]) f2 = 1;
		}
		pre = x;
		if (f1 == f2 && f1 == 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		flag1 = f1;
		flag2 = f2;
	}
	cout << "YES" << endl;
	return 0;
}
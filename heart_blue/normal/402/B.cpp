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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
#define ABS(x) ((x) > 0 ? (x):(-x))
const int N = 1001;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int key = 0;
	int maxv = 1 << 30;
	for (int i = 0; i < n; i++)
	{
		int p = a[i] - i*k;
		if (p < 1) p = 1;
		int tmp = 0;
		for (int j = 0; j < n; j++)
		{
			if(p != a[j]) tmp++;
			p += k;
		}
		if (tmp < maxv) maxv = tmp, key = i;
	}
	int p = a[key] - key*k;
	if (p < 1) p = 1;
	cout << maxv << endl;
	for (int i = 0; i < n; i++)
	{
		if (p < a[i]) cout << '-' << ' ' << i + 1 << ' ' << a[i] - p << endl;
		if (p > a[i]) cout << '+' << ' ' << i + 1 << ' ' << p - a[i] << endl;
		p += k;
	}
	return 0;
}
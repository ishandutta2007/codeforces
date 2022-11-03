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

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	if (n / 2 > k)
	{
		cout << -1 << endl;
		return 0;
	}
	if (n == 1)
	{
		if( k == 0) cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	int t = k - n / 2 + 1;
	cout << t << ' ' << t * 2;
	n -= 2;
	for (int i = 1e9; i >= 0; i--)
	{
		if (n <= 0) break;
		cout << ' ' << i;
		n--;
	}
	cout << endl;
	return 0;
}
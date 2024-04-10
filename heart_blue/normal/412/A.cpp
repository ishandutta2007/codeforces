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
const long long INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	string str;
	cin >> n >> k;
	k--;
	cin >> str;
	n--;
	if (n - k < k - 0)
	{
		for (int i = k; i < n; i++)
		{
			cout << "RIGHT" << endl;
		}
		cout << "PRINT " << str[n] << endl;
		for (int i = n-1; i >= 0; i--)
		{
			cout << "LEFT" << endl;
			cout << "PRINT " << str[i] << endl;
		}
		
	}
	else
	{
		for (int i = k; i > 0; i--)
		{
			cout << "LEFT" << endl;
		}
		cout << "PRINT " << str[0] << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << "RIGHT" << endl;
			cout << "PRINT " << str[i] << endl;
		}
	}
	return 0;
}
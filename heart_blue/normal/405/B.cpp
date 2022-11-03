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
const int N = 3001;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	string str;
	int n;
	cin >> n >> str;
	MEM(a, 0);
	int t = 0;

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'L') t = -1;
		else if (str[i] == 'R') t = 1;
		else continue;
		a[i] = t;
		for (int j = i+t; j >= 0 && j < n; j += t)
		{
			if (str[j] != '.') break;
			a[j] += j - i + t;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
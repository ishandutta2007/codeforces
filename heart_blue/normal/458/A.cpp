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
const int N = 5e5+10;
const int M = 1e4;

int a[N];
int b[N];

void check(int *a,int& n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] == 1 && a[i + 1] == 1)
		{
			a[i + 2] ++;
			a[i] = 0;
			a[i + 1] = 0;
			n = max(i + 3, n);
			i = i + 3;
			
		}
	}
}

int getans(int n, int m)
{
	if (n < m) return -1;
	if (n > m) return 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}
	return 0;
}
void dezo(int *a, int &n)
{
	while (n >= 0 && a[n] == 0) n--;
}
int main()
{
	//freopen("input.txt", "r", stdin);

	string s1;
	string s2;
	cin >> s1 >> s2;
	int n = 0;
	int m = 0;
	for (int i = s1.length()-1; i >= 0; i--)
	{
		a[n++] = s1[i] - '0';
	}
	for (int i = s2.length() - 1; i >= 0; i--)
	{
		b[m++] = s2[i] - '0';
	}
	check(a, n);
	check(b, m);
	dezo(a, n);
	dezo(b, m);
	int t = getans(n, m);
	if (t == 0) cout << "=" << endl;
	if (t == 1) cout << ">" << endl;
	if (t == -1) cout << "<" << endl;
	return 0;

}
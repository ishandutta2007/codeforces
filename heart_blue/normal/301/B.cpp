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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
int a[100];
int x[100];
int y[100];
long long m[100][100];
int main()
{
	int n,d;
	cin >> n >> d;
	MEM(a,0);
	for(int i = 1; i < n-1; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			m[i][j] = a[i];
			m[i][j] -= (abs(x[i]-x[j])+abs(y[i]-y[j]))*d;
		}
	}
	for(int v = 0; v < n; v++)
	{
		for(int i = 0; i < n; i++)
		{
			if(i == v) continue;
			for(int j = 0; j < n; j++)
			{
				if(i == j || j == v) continue;
				m[i][j] = MAX(m[i][j], m[i][v] + m[v][j]);
			}
		}
	}
	if(m[0][n-1] >= 0) m[0][n-1] = 0;
	cout << -m[0][n-1] << endl;

	return 0;
}
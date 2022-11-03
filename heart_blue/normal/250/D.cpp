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
ifstream fin("aa.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
const int M = 1e5;
double a[M+1];
double b[M+1];
double c[M+1];
int main()
{
	int n,m;
	double u,v;
	cin >> n >> m;
	int l,r;
	l = r = 0;
	cin >> u >> v;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	for(int i = 0; i < m; i++)
		cin >> c[i];
	double dis = v - u;
	int x,y;
	double ans = 1e9;
	for(r = 0; r < m; r++)
	{
		double t = b[r]/v*u;
		while(a[l] < t)
		{
			if(l == n-1)
				break;
			l++;
		}
		int tx = l;
		int ty = r;
		double total = sqrt(dis*dis+(a[l]-b[r])*(a[l]-b[r])) + c[r] + sqrt(u*u+a[l]*a[l]);
		if(l > 0)
		{
			double tmp = sqrt(dis*dis+(a[l-1]-b[r])*(a[l-1]-b[r])) + c[r] + sqrt(u*u+a[l-1]*a[l-1]);
			if(tmp < total)
			{
				total = tmp;
				tx--;
			}
		}
		if(total < ans)
		{
			x = tx;
			y = ty;
			ans = total;
		}
	}
	cout << x+1 << ' ' << y+1 << endl;

	return 0;
}
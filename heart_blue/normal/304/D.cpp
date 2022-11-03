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
const int INF = 0x3f3f3f3f;
const int N = 1020;


void getans(int& ans, int l, int r)
{
	if(ans >= r)
	{
		ans = r;
	}
	else if(ans >= l)
	{
		ans = ans;
		
	}
	else
	{
		ans = l;
	}
}
int gcd(int n,int m)
{
	if(n < m)
	{
		int t = n; n = m; m = t;
	}
	while(n%m)
	{
		int t = n%m;
		n = m;
		m = t;
	}
	return m;
}
int main()
{
	int n,m,x,y,a,b;
	cin >> n >> m >> x >> y >> a >> b;
	int g = gcd(a,b);
	a /= g;
	b /= g;
	int t = MIN(n/a,m/b);
	int ta = t*a;
	int tb = t*b;
	int lx = 0;
	int rx = n-ta;
	int ly = 0;
	int ry = m-tb;
	x = 2*x;
	y = 2*y;
	int ansx = x;
	int ansy = y;
	getans(ansx,ta,ta+rx*2);
	getans(ansy,tb,tb+ry*2);
	ansx-=ta;
	ansy-=tb;
	ansx/=2;
	ansy/=2;
	cout << ansx << ' ' << ansy << ' ' << ansx+ta << ' ' << ansy+tb << endl;
	return 0;

}
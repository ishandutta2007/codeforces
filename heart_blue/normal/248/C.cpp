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

const double eps = 1e-8;
double dis(double x0, double y0, double x1, double y1, double x2, double y2)//(X0,Y0)
{
	double k = (y2 - y1) / (x2 - x1);
	return fabs((x0 * k - y0 + y1) / sqrt(k * k + 1));
}
int main()
{
	int n;
	double l, r;
	int line;
	int x, y;
	int rd;
	int tr, tl;
	cin >> tl >> tr >> line >> x >> y >> rd;
	int flag = 0;
	line -= rd;
	double m;
	r = 2 * line - tl;
	l = 2 * line - tr;
	double a, b, c;
	m = r - rd;
	a = y - m;
	b = -x;
	c = x * m;
	double xw = (-b * line - c) / a;
	if (dis(0, tr, 0, tl + rd, xw, line) - rd > 1e-8)
	{
		printf("%.15f\n", xw);
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}
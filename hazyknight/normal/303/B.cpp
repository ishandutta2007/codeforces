#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,m,x,y,a,b;

int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
	int g = __gcd(a,b);
	a /= g;
	b /= g;
	int xa = 0,xb = min(n / a,m / b) * a,ya = 0,yb = min(n / a,m / b) * b;
	double mx = xb / 2.,my = yb / 2.;
	if (x > mx)
	{
		int dis = min((int)(x - mx),n - xb);
		xb += dis;
		xa += dis;
	}
	if (y > my)
	{
		int dis = min((int)(y - my),m - yb);
		yb += dis;
		ya += dis;
	}
	printf("%d %d %d %d\n",xa,ya,xb,yb);
	return 0;
}
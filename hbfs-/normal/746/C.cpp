#include <iostream>
#include <cstdio>

using namespace std;
int s,x1,x2,t1,t2,p,d;
int Abs(int x) { return x > 0 ? x : -x; }
int main()
{
	scanf("%d%d%d",&s,&x1,&x2);
	scanf("%d%d",&t1,&t2);
	scanf("%d%d",&p,&d);
	int ans = Abs(x1-x2) * t2;
	int t = 0;
	if (x1 >= p && d > 0) t = (x1-p) * t1;
	if (x1 <=  p && d < 0) t = (p-x1) * t1;
	if (x1 > p && d < 0) t = (p+x1) * t1 , d = 1;
	if (x1 <  p && d > 0) t = (s-p+s-x1) * t1 , d = -1;
	
	if (x2 >= x1 && d > 0) t += (x2-x1) * t1;
	if (x2 <  x1 && d < 0) t += (x1-x2) * t1;
	if (x2 >= x1 && d < 0) t += (x1+x2) * t1;
	if (x2 <  x1 && d > 0) t += (s-x1+s-x2) * t1;
	ans = min(ans,t);
	printf("%d\n",ans);
	return 0;
}
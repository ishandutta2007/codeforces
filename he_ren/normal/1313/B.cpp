#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	
	int a = (x-1) - (n-(y+2)+1);
	++a;
	if(a<1) a=1;
	if(a>n) a=n;
	printf("%d ",a);
	
	int b = (n-x) - (y-1);
	b=n-b;
	if(b<1) b=1;
	if(b>n) b=n;
	printf("%d\n",b);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

/*n=9
  x<n        x
       1 2 3 4 5 6 7 8 9
  y>x  1 9 8 6 7 5 4 3 2
             
  y<x  7 6 5 3 4 2 1 8 9
  y=x  8 7 6 4 5 3 2 1 9
  
  x=n                  x
       1 2 3 4 5 6 7 8 9
  y=x  1 8 7 6 5 4 3 2 9
  y<x                9 7
*/
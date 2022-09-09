#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long double ldb;
typedef double db;

void solve(void)
{
	int tmp;
	scanf("%d",&tmp);
	ldb d=tmp;
	ldb delta = d*d - 4*d;
	if(delta<0){ printf("N\n"); return;}
	
	ldb a = (d+sqrt(delta))/2;
	ldb b = (d-sqrt(delta))/2;
	if(a<0 || b<0){ printf("N\n"); return;}
	printf("Y %.20lf %.20lf\n",(db)a,(db)b); 
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
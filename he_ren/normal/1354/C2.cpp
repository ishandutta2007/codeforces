#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;

int n;
ldb deg, r1,r2,d1,d2;

inline ldb calc(int x)
{
	return r1 * sin(deg*(x-1)/2) * 2;
}

void solve(void)
{
	scanf("%d",&n);
	
	const ldb pi = acos(-1);
	
	deg = pi/n;
	r1 = 0.5 / sin(deg/2);
	r2 = 0.5 / tan(deg/2);
	d1 = r1 * 2;
	d2 = r2 * 2;
	
	ldb a = calc((n+1)/2);
	ldb b = calc((n+1)/2+1);
	printf("%.20lf\n",(db)((a+b)/sqrt(2)));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
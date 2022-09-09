#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	const ldb pi = acos(-1);
	
	ldb r = 0.5 / tan(pi/n * 0.5);
	ldb d = r * 2;
	
	printf("%.20lf\n",(db)d);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
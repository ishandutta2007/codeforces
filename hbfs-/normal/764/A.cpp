#include <iostream>
#include <cstdio>

using namespace std;
int gcd(int x,int y ) { return y == 0 ? x : gcd(y,x%y); }
int main() {
	int n,m,z;
	scanf("%d%d%d",&n,&m,&z);
	int ans = z / (n*m/gcd(n,m));
	printf("%d\n",ans);
	return 0;
}
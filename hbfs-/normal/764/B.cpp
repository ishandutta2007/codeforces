#include <iostream>
#include <cstdio>
#define N 400050

using namespace std;
int gcd(int x,int y ) { return y == 0 ? x : gcd(y,x%y); }
int a[N],n;
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) 
		if ((i&1) && i<=n-i+1) 
			swap(a[i],a[n-i+1]);
	for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}
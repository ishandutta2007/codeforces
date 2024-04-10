#include <bits/stdc++.h>
#define N 1000050
using namespace std;
int n,m,x[N];
int main() {
	scanf("%d%d",&n,&m);
	x[m] = 1;
	n %= 6;
	for (int i=n;i>=1;i--) {
		if (i%2 == 1)
			swap(x[0],x[1]);
		else
			swap(x[1],x[2]);
	}
	for (int i=0;i<=2;i++) if (x[i]) printf("%d\n",i);
	return 0;
}
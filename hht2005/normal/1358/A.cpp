#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n,m;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		printf("%d\n",n*m/2+n*m%2);
	}
	return 0;
}
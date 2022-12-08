#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n,k;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		int f=2;
		for(;f*f<=n;f++)
			if(n%f==0)break;
		if(n%f!=0)f=n;
		n+=f;
		n+=2*(k-1);
		printf("%d\n",n);
	}
	return 0;
}
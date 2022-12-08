#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int sum=1e9,t=sqrt(n);
		for(int i=max(1,t-3);i<=t+3;i++)
			sum=min(sum,(i-1)+(n/i)-1+(n%i!=0));
		printf("%d\n",sum);
	}
	return 0;
}
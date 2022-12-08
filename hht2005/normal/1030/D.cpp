#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(2ll*n*m%k) {
		puts("NO");
		return 0;
	}
	int N=n;
	if(k&1) {
		for(int i=2;i*i<=k;i++) {
			while(k%i==0) {
				if(n%i==0)n/=i;
				else m/=i;
				k/=i;
			}
		}
		if(k>1) {
			if(n%k==0)n/=k;
			else m/=k;
		}
		if(2*n<=N)n*=2;
		else m*=2;
		puts("YES");
		puts("0 0");
		printf("%d 0\n",n);
		printf("0 %d\n",m);
	} else {
		k/=2;
		for(int i=2;i*i<=k;i++) {
			while(k%i==0) {
				if(n%i==0)n/=i;
				else m/=i;
				k/=i;
			}
		}
		if(k>1) {
			if(n%k==0)n/=k;
			else m/=k;
		}
		puts("YES");
		puts("0 0");
		printf("%d 0\n",n);
		printf("0 %d\n",m);
	}
	return 0;
}
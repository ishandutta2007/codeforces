#include<bits/stdc++.h>
using namespace std;
const int N=100;
int a[N];
int main() {
	int T,n;
	cin>>T;
	while(T--) {
		scanf("%d",&n);
		int c0=0,c1=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			if(a[i]==0)c0++;
			if(a[i]==1)c1++;
		}
		printf("%lld\n",c1*(1ll<<c0));
	}
	return 0;
}
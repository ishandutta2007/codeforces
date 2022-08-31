#include<bits/stdc++.h>
using namespace std;
long long a[4],b[4],c,i,n;
int main(){
	for(i=1;i<=3;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	
	printf("First\n1000000000\n");
	fflush(stdout);
	scanf("%d",&n);
	a[n]+=1e9;b[n]=a[n];
	sort(b+1,b+4);
	c=2*b[3]-b[1]-b[2];
	printf("%lld\n",c);
	fflush(stdout);
	scanf("%d",&n);
	a[n]+=c;
	sort(a+1,a+4);
	printf("%lld\n",a[3]-a[2]);
	return 0;
}
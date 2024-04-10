#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	printf("1 1\n%lld\n",-a[1]),a[1]=0;
	if(n==1){
		puts("1 1\n0\n1 1\n0");
		return 0; 
	}
	printf("2 %d\n",n);
	for(int i=2;i<=n;i++){
		printf("%lld ",1ll*a[i]*(n-1)),a[i]*=n;
	}
	puts("");
	printf("1 %d\n",n);
	for(int i=1;i<=n;i++)printf("%lld ",-a[i]);
    return 0;
}
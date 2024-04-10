#include<bits/stdc++.h>
using namespace std;
#define N 505
int main(){
	int n,m;
	long long int ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int a=i%5;
		ans+=(m+a)/5;
	} 
	printf("%I64d\n",ans);
	return 0;
}
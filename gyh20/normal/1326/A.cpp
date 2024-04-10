#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1)puts("-1");
		else {
			for(int i=1;i<n;++i)putchar('3');
			puts("4");
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
int n,a[101],ans[101];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		if(i&1){
			ans[l++]=a[i];
		}
		else{
			ans[r--]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
#include<stdio.h>
int n;
int ans;
int a[100100];
int stk[100100];
int p;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		while(p!=0&&a[i]>stk[p-1]){
			p--;
			if(ans<(a[i]^stk[p]))ans=a[i]^stk[p];
		}
		if(p!=0){
			if(ans<(a[i]^stk[p-1]))ans=a[i]^stk[p-1];
		}
		stk[p]=a[i];
		p++;
	}
	printf("%d",ans);
}
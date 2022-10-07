#include<stdio.h>
#include<algorithm>
int n,m;
int p,q;
int a[200100];
int ans;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0)p++;
		else q++;
	}
	if(n==m){
		if(q%2==1){
			printf("Stannis");
		}
		else{
			printf("Daenerys");
		}
	}
	else if((n-m)%2==0){
		j=(n-m)/2;
		if(j>=p&&m%2==1){
			printf("Stannis");
		}
		else{
			printf("Daenerys");
		}
	}
	else{
		j=(n-m)/2;
		if(j>=p&&m%2==0){
			printf("Daenerys");
		}
		else if(j>=q){
			printf("Daenerys");
		}
		else{
			printf("Stannis");
		}
	}
}
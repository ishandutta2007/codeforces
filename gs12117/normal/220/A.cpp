#include<stdio.h>
#include<algorithm>
int n;
int a[100100];
int b[100100];
int ans;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	std::sort(b,b+n);
	for(i=0;i<n;i++){
		if(b[i]!=a[i])ans++;
	}
	if(ans>2){
		printf("NO");
	}
	else{
		printf("YES");
	}
}
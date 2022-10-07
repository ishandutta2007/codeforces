#include<stdio.h>
#include<algorithm>
int n;
int m;
int a[100100];
int b[100100];
int ans;
int main(){
	int i,j;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	a[m]=999999999;
	m++;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	std::sort(a,a+m);
	std::sort(b,b+n);
	j=a[0];
	for(i=n-1;i>=0;i--){
		j--;
		ans+=b[i];
		if(j==0){
			i-=2;
			j=a[0];
		}
	}
	printf("%d",ans);
}
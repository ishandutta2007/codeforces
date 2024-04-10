#include<stdio.h>
int tc;
int n,m;
int a[10];
int main(){
	int i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&n,&m);
		m--;
		for(i=0;i<n-1;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		j=m;
		for(i=0;i<n-1;i++){
			j+=n-a[i];
			j%=n;
		}
		j++;
		printf("%d\n",j);
	}
}
#include<stdio.h>
#include<algorithm>
int n,m;
int a[100100];
int chk[100100];
int ans;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		printf("%d",n);
		return 0;
	}
	std::sort(a,a+n);
	ans=n;
	j=0;
	for(i=0;i<n;i++){
		while(j<i&&a[i]/a[j]>m||(a[i]/a[j]==m&&a[i]%a[j]!=0))j++;
		if(a[i]/a[j]==m&&a[i]%a[j]==0){
			if(chk[j]==0){
				ans--;
				chk[i]=1;
			}
		}
	}
	printf("%d",ans);
}
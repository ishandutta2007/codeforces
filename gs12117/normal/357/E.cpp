#include<stdio.h>
int n;
int a[10];
int main(){
	int i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[t]++;
	}
	int ans=0;
	int b=0;
	for(i=0;i<5;i++){
		b+=i*a[i];
	}
	if((b<3&&b!=0)||b==5){
		printf("-1");
		return 0;
	}
	if(a[1]<a[2]){
		ans+=a[1];
		a[2]-=a[1];
		ans+=(a[2]/3)*2;
		a[2]%=3;
		if(a[4]>=a[2])ans+=a[2];
		else{
			ans+=2;
		}
	}
	else{
		ans+=a[2];
		a[1]-=a[2];
		ans+=(a[1]/3)*2;
		a[3]+=a[1]/3;
		a[1]%=3;
		if(a[3]>=a[1])ans+=a[1];
		else ans+=2;
	}
	printf("%d",ans);
	return 0;
}
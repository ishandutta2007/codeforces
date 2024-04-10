#include<stdio.h>
int b,d;
char a[11000];
char c[110];
int dp[110];
int dpb[110][3];
int lena,lenc;
int ans;
int main(){
	int i,j,t;
	scanf("%d%d%s%s",&b,&d,&a,&c);
	for(lena=0;a[lena];lena++);
	for(lenc=0;c[lenc];lenc++);
	for(i=0;i<lenc;i++){
		t=i;
		for(j=0;j<lena;j++){
			if(a[j]==c[t%lenc]){
				t++;
			}
		}
		if(t==i){
			printf("0");
			return 0;
		}
		dp[i]=t;
	}
	t=0;
	ans=0;
	for(i=0;i<b;i++){
		if(dpb[t][2]==1){
			j=(b-i)/(i-dpb[t][0]);
			ans+=j*(ans-dpb[t][1]);
			i+=j*(i-dpb[t][0]);
			break;
		}
		dpb[t][0]=i;
		dpb[t][1]=ans;
		dpb[t][2]=1;
		t=dp[t];
		ans+=t/lenc;
		t%=lenc;
	}
	for(;i<b;i++){
		t=dp[t];
		ans+=t/lenc;
		t%=lenc;
	}
	printf("%d",ans/d);
}
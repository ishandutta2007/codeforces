#include<stdio.h>
int n;
int a[100100];
int st[100100];
int b[100100];
int ud[100100];
int sp;
int ans;
int main(){
	int i,j,k,max;
	max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>max){
			ud[i]=1;
			max=a[i];
		}
	}
	for(i=n-1;i>=0;i--){
		if(ud[i]==0){
			while(sp>0&&st[sp-1]<a[i])sp--;
			st[sp]=a[i];
			sp++;
			if(sp>ans)ans=sp;
		}
		else sp=0;
	}
	printf("%d",ans);
}
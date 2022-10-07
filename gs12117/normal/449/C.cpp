#include<stdio.h>
int n;
int chk[100100];
int ans[100100];
int ansn;
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=3;i<=n/2;i+=2){
		k=0;
		for(j=1;j*i<=n;j++){
			if(chk[i*j]==0)k++;
		}
		if(k%2==0){
			for(j=1;j*i<=n;j++){
				if(chk[i*j]==0){
					chk[i*j]=1;
					ans[ansn]=i*j;
					ansn++;
				}
			}
		}
		else{
			for(j=1;j*i<=n;j++){
				if(chk[i*j]==0&&j!=2){
					chk[i*j]=1;
					ans[ansn]=i*j;
					ansn++;
				}
			}
		}
	}
	for(i=2;i<=n;i+=2){
		if(chk[i]==0){
			ans[ansn]=i;
			ansn++;
		}
	}
	printf("%d\n",ansn/2);
	for(i=0;i<ansn/2;i++){
		printf("%d %d\n",ans[i*2],ans[i*2+1]);
	}
}
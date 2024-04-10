#include<stdio.h>
int n;
char a[106][106];
int b[106][106];
int c[106];
int d[106];
int chk[106];
int ansn;
int ans[106];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]=='1')b[i][j]=1;
			else b[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			d[j]+=b[i][j];
		}
	}
	while(1){
		for(i=0;i<n;i++){
			if(c[i]==d[i])break;
		}
		if(i==n)break;
		chk[i]=1;
		for(j=0;j<n;j++){
			d[j]-=b[i][j];
		}
	}
	for(i=0;i<n;i++){
		if(chk[i]==0){
			ans[ansn]=i;
			ansn++;
		}
	}
	printf("%d\n",ansn);
	for(i=0;i<ansn;i++){
		printf("%d ",ans[i]+1);
	}
}
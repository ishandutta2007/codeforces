#include<stdio.h>
int n,qry;
int a[1001000];
long long int b[53];
int nxt[1001000];
int chk[1001000];
long long int sum[1001000];
int ans;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&qry);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum[i+1]=sum[i]+a[i];
	}
	for(i=0;i<qry;i++){
		scanf("%I64d",&b[i]);
		if(sum[n]<=b[i]){
			printf("1\n");
			continue;
		}
		k=0;
		for(j=0;j<n;j++){
			chk[j]=0;
			while(sum[j+1]>sum[k]+b[i]){
				nxt[k]=j;
				k++;
			}
		}
		for(j=0;j<n;j++){
			while(k<n&&sum[j+1]+sum[n]>sum[k]+b[i]){
				nxt[k]=j;
				k++;
			}
			if(k==n)break;
		}
		j=0;
		while(chk[j]==0){
			chk[j]=1;
			j=nxt[j];
		}
		int flag=0;
		k=j;
		for(ans=0;flag==0||(j<k&&flag==1);ans++){
			if(nxt[j]<j)flag++;
			j=nxt[j];
		}
		printf("%d\n",ans);
	}
}
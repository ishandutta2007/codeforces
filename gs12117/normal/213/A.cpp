#include<stdio.h>
int n;
int a[210];
int b[210][210];
int bn[210];
int chk[210];
int ans;
int main(){
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	for(i=0;i<n;i++){
		scanf("%d",&bn[i]);
		for(j=0;j<bn[i];j++){
			scanf("%d",&b[i][j]);
			b[i][j]--;
		}
	}
	ans=999999999;
	for(i=0;i<3;i++){
		for(j=0;j<n;j++){
			chk[j]=0;
		}
		for(j=0;;j++){
			for(k=0;k<n;k++){
				if(chk[k]==0&&a[k]==(i+j)%3){
					for(l=0;l<bn[k];l++){
						if(chk[b[k][l]]==0)break;
					}
					if(l==bn[k]){
						chk[k]=1;
						k=-1;
					}
				}
			}
			for(k=0;k<n;k++){
				if(chk[k]==0)break;
			}
			if(k==n)break;
		}
		if(ans>j)ans=j;
	}
	printf("%d",ans+n);
}
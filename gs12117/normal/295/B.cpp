#include<stdio.h>
int n;
int a[510][510];
int sd[510][510];
int b[510];
long long int ans[510];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			sd[i][j]=a[i][j];
		}
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		b[i]--;
	}
	for(i=n-1;i>=0;i--){
		for(j=i+1;j<n;j++){
			for(k=i+1;k<n;k++){
				if(sd[b[i]][b[j]]>sd[b[i]][b[k]]+sd[b[k]][b[j]])sd[b[i]][b[j]]=sd[b[i]][b[k]]+sd[b[k]][b[j]];
				if(sd[b[j]][b[i]]>sd[b[j]][b[k]]+sd[b[k]][b[i]])sd[b[j]][b[i]]=sd[b[j]][b[k]]+sd[b[k]][b[i]];
			}
		}
		for(j=i+1;j<n;j++){
			for(k=i+1;k<n;k++){
				if(sd[b[j]][b[k]]>sd[b[j]][b[i]]+sd[b[i]][b[k]])sd[b[j]][b[k]]=sd[b[j]][b[i]]+sd[b[i]][b[k]];
			}
		}
		for(j=i;j<n;j++){
			for(k=i;k<n;k++){
				ans[i]+=sd[b[j]][b[k]];
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%I64d ",ans[i]);
	}
}
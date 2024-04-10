#include<stdio.h>
int n,m;
int w[510];
int b[1010];
int chk[1010];
int ans;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
		b[i]--;
		for(j=i-1;j>=0;j--){
			if(b[i]==b[j]){
				chk[j]=1;
				break;
			}
			if(chk[j]==0)ans+=w[b[j]];
		}
	}
	printf("%d",ans);
}
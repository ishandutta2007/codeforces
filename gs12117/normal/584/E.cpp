#include<stdio.h>
int n;
int a[2010];
int b[2010];
int c[2010];
int m;
int ans[2001000][2];
int main(){
	int i,j,k,t,p;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		c[b[i]]=i;
	}
	for(i=0;i<n;i++){
		a[i]=c[a[i]];
	}
	p=0;
	for(i=0;i<n;i++){
		if(a[i]>i){
			for(j=i+1;j<n;j++){
				if(a[j]==i)break;
			}
			for(k=j-1;k>=i;k--){
				if(a[k]>=j){
					p+=j-k;
					ans[m][0]=k;
					ans[m][1]=j;
					m++;
					t=a[j];
					a[j]=a[k];
					a[k]=t;
					j=k;
				}
			}
		}
	}
	printf("%d\n",p);
	printf("%d\n",m);
	for(i=0;i<m;i++){
		printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
	}
}
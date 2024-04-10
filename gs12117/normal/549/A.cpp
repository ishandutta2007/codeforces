#include<stdio.h>
#include<algorithm>
int n,m;
char a[56][56];
int ans;
int d[10];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	ans=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<m-1;j++){
			d[0]=a[i][j];
			d[1]=a[i+1][j];
			d[2]=a[i][j+1];
			d[3]=a[i+1][j+1];
			std::sort(d,d+4);
			if(d[0]=='a'&&d[1]=='c'&&d[2]=='e'&&d[3]=='f')ans++;
		}
	}
	printf("%d",ans);
}
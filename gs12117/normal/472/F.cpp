#include<stdio.h>
int n;
int a[10100];
int b[10100];
int ans[1001000][2];
int ansl;
int c[10100];
int d[500100][2];
int dl;
void gelim(){
	int i,j,p;
	p=0;
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			if((c[i]^c[j])<c[i]){
				c[i]^=c[j];
				d[dl][0]=i;
				d[dl][1]=j;
				dl++;
			}
		}
		if(c[i]!=0){
			if(i==p)p++;
			else{
				c[p]^=c[i];
				d[dl][0]=p;
				d[dl][1]=i;
				dl++;
				c[i]^=c[p];
				d[dl][0]=i;
				d[dl][1]=p;
				dl++;
				p++;
			}
			j=p-1;
			while(j!=0&&c[j-1]<c[j]){
				c[j]^=c[j-1];
				d[dl][0]=j;
				d[dl][1]=j-1;
				dl++;
				c[j-1]^=c[j];
				d[dl][0]=j-1;
				d[dl][1]=j;
				dl++;
				c[j]^=c[j-1];
				d[dl][0]=j;
				d[dl][1]=j-1;
				dl++;
				j--;
			}
		}
	}
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		c[i]=a[i];
	}
	gelim();
	for(i=0;i<dl;i++){
		ans[ansl][0]=d[i][0];
		ans[ansl][1]=d[i][1];
		ansl++;
	}
	dl=0;
	for(i=0;i<n;i++){
		a[i]=c[i];
	}
	for(i=0;i<n;i++){
		c[i]=b[i];
	}
	gelim();
	for(i=0;i<n&&a[i]!=0;i++){
		for(j=i;j<n&&a[j]!=0;j++){
			if((a[i]^c[i])>((a[i]^c[i])^a[j])){
				a[i]^=a[j];
				ans[ansl][0]=i;
				ans[ansl][1]=j;
				ansl++;
			}
		}
		if(a[i]!=c[i]){
			printf("-1");
			return 0;
		}
	}
	if(c[i+1]!=0){
		printf("-1");
		return 0;
	}
	for(i=dl-1;i>=0;i--){
		ans[ansl][0]=d[i][0];
		ans[ansl][1]=d[i][1];
		ansl++;
	}
	printf("%d\n",ansl);
	for(i=0;i<ansl;i++){
		printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
	}
}
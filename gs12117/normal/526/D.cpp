#include<stdio.h>
int n,m;
char a[1001000];
int ff[1001000];
int main(){
	int i,j;
	scanf("%d%d%s",&n,&m,a);
	ff[0]=-1;
	for(i=1;i<=n;i++){
		j=ff[i-1];
		while(j!=-1&&a[i-1]!=a[j]){
			j=ff[j];
		}
		j++;
		ff[i]=j;
		j=i-ff[i];
		if(i%j==0){
			j=i/j;
			if(j%m<=j/m)printf("1");
			else printf("0");
		}
		else{
			j=i/j;
			if(j%m<j/m)printf("1");
			else printf("0");
		}
	}
}
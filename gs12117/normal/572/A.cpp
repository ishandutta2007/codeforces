#include<stdio.h>
int na,nb;
int ma,mb;
int a[100100];
int b[100100];
int main(){
	int i;
	scanf("%d%d%d%d",&na,&nb,&ma,&mb);
	for(i=0;i<na;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<nb;i++){
		scanf("%d",&b[i]);
	}
	if(a[ma-1]<b[nb-mb])printf("YES");
	else printf("NO");
}
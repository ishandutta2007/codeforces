#include<stdio.h>
int n,m;
int a[30100];
int p[30100];
int main(){
	int i;
	scanf("%d%d",&n,&m);
	n--;
	m--;
	p[0]=1;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(p[i]==1)p[i+a[i]]=1;
	}
	if(p[m])printf("YES");
	else printf("NO");
}
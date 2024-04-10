#include<stdio.h>
int n,m;
char a[100100];
char b[100100];
char c[100100];
int p;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	scanf("%s%s",a,b);
	p=0;
	for(i=0;i<n;i++){
		if(a[i]!=b[i])p++;
	}
	if(p>2*m)printf("-1");
	else{
		for(i=0;i<n;i++){
			c[i]=a[i];
			if(a[i]!=b[i]){
				c[i]++;
				if(c[i]>'z')c[i]-=26;
				if(b[i]==c[i]){
					c[i]++;
					if(c[i]>'z')c[i]-=26;
				}
			}
		}
		if(p>m){
			j=0;
			for(i=0;j<p-m;i++){
				if(c[i]!=a[i]){
					c[i]=a[i];
					j++;
				}
			}
			j=0;
			for(;j<p-m;i++){
				if(c[i]!=b[i]){
					c[i]=b[i];
					j++;
				}
			}
		}
		else{
			j=0;
			for(i=0;j<m-p;i++){
				if(c[i]==a[i]){
					c[i]++;
					if(c[i]>'z')c[i]-=26;
					j++;
				}
			}
		}
	}
	printf("%s",c);
}
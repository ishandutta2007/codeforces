#include<stdio.h>
int n;
char a[100100];
int p,ls;
int main(){
	int i,j;
	scanf("%s",a);
	for(n=0;a[n];n++);
	for(i=0;i<n;i++){
		if(a[i]=='(')p++;
		if(a[i]==')')p--;
		if(a[i]=='#'){
			p--;
			ls=i;
		}
		if(p<0){
			printf("-1");
			return 0;
		}
	}
	j=0;
	for(i=0;i<n;i++){
		if(a[i]=='(')j++;
		if(a[i]==')')j--;
		if(a[i]=='#'){
			j--;
			if(i==ls)j-=p;
		}
		if(j<0){
			printf("-1");
			return 0;
		}
	}
	for(i=0;i<n;i++){
		if(i==ls)printf("%d\n",p+1);
		else if(a[i]=='#')printf("1\n");
	}
}
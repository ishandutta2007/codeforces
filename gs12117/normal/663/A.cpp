#include<stdio.h>
char s[100];
int q[1000];
int n,m,z;
int main(){
	int i,t,r;
	while(1){
		scanf("%s",s);
		m++;
		scanf("%s",s);
		if(s[0]=='+'){
			q[m]=0;
		}
		else if(s[0]=='-'){
			q[m]=1;
			z++;
		}
		else{
			break;
		}
	}
	scanf("%d",&n);
	if((m-z)*n-z<n){
		puts("Impossible");
		return 0;
	}
	if(m-z-(z*n)>n){
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	t=n-(m-z-z);
	for(i=0;i<m;i++){
		if(q[i]==0){
			if(t>0){
				r=1+t;
				if(r>n)r=n;
				t-=r-1;
			}
			else r=1;
		}
		else{
			if(t<0){
				r=1-t;
				if(r>n)r=n;
				t+=r-1;
			}
			else r=1;
		}
		printf("%d ",r);
		if(i==m-1)break;
		if(q[i+1]==0)printf("+ ");
		else printf("- ");
	}
	printf("= %d",n);
	return 0;
}
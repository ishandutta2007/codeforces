#include<stdio.h>
int n,m,s,f;
int t,l,r;
int main(){
	int i,j;
	scanf("%d%d%d%d",&n,&m,&s,&f);
	j=1;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&t,&l,&r);
		while(j<t){
			if(s==f)return 0;
			if(s<f){
				printf("R");
				s++;
			}
			if(s>f){
				printf("L");
				s--;
			}
			j++;
		}
		if(s==f)return 0;
		if(s<f){
			if(s<=r&&s+1>=l)printf("X");
			else{
				printf("R");
				s++;
			}
		}
		else{
			if(s-1<=r&&s>=l)printf("X");
			else{
				printf("L");
				s--;
			}
		}
		j++;
	}
	while(1){
		if(s==f)return 0;
		if(s<f){
			printf("R");
			s++;
		}
		if(s>f){
			printf("L");
			s--;
		}
	}
}
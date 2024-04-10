#include<cstdio>
int n,k,l,S;
int main(){
	scanf("%d",&k),l=1<<18,S=l-1,l>>=1;
	printf("%d %d\n%d %d %d\n%d %d %d\n%d %d %d",3,3,S,S,l,S,k,S,l,S,S/2);
	return 0;
}
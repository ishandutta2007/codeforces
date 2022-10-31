#include<stdio.h>
long long C[61][61];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	C[0][0]=1;
	for(int i=0;i<60;i++){
		for(int j=0;j<=i;j++){
			C[i+1][j]+=C[i][j];
			C[i+1][j+1]+=C[i][j];
		}
	}
	long long ret=C[a+b][c];
	for(int i=0;i<4;i++)ret-=C[a][i]*C[b][c-i];
	ret-=C[a][c];
	printf("%I64d\n",ret);
}
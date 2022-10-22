#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef double db;
int n,m,x,y;
#define Maxn 1010
db f[Maxn][Maxn];
db num[Maxn][Maxn];
int equ,var;
/*
f[i+1][1]/3+1=2/3f[i][1]-f[i][2]/3
f[i+1][j]/4+1=-f[i][j-1]/4+3/4f[i][j]-f[i][j+1]/4
f[i+1][m]/3+1=-f[i][m-1]/3+2/3f[i][m]
*/
void Build(int x){
	equ=m;var=m;
	num[1][1]=2.0/3.0;num[1][2]=-1.0/3.0;num[1][var+1]=f[x+1][1]/3.0+1.0;
	num[m][m-1]=-1.0/3.0;num[m][m]=2.0/3.0;num[m][var+1]=f[x+1][m]/3.0+1.0;
	for(int i=2;i<m;++i){
	    num[i][i-1]=-1.0/4.0;
		num[i][i]=3.0/4.0;
		num[i][i+1]=-1.0/4.0;
		num[i][var+1]=f[x+1][i]/4.0+1;
    }
}
void Gauss(int x){
	for(int i=1;i<=equ;++i){
		db tmp=num[i+1][i]/num[i][i];
		num[i+1][i]-=tmp*num[i][i];num[i+1][i+1]-=tmp*num[i][i+1];
		num[i+1][var+1]-=tmp*num[i][var+1];
	}
	f[x][var]=num[equ][var+1]/num[equ][var];
	for(int i=var-1;i>=1;--i)
	f[x][i]=(num[i][var+1]-f[x][i+1]*num[i][i+1])/num[i][i];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	if(m==1){
		printf("%d\n",(n-x)*2);
		return 0;
	}
	for(int i=n-1;i>=x;--i){
		Build(i);
		Gauss(i);
	}
	printf("%.10lf\n",f[x][y]);
	return 0;
}
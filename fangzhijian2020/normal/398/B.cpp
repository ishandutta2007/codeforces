#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a; 
}
int n,m,tx,ty,x,y,visx[2005],visy[2005];double f[2005][2005];
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		x=read();y=read();
		if(!visx[x]){++tx;visx[x]=1;}
		if(!visy[y]){++ty;visy[y]=1;}
	}
	for(int i=n;~i;--i){
		for(int j=n;~j;--j){
			if(i==n&&j==n)continue;
			f[i][j]=(f[i+1][j]*(n-i)*j+f[i][j+1]*i*(n-j)+f[i+1][j+1]*(n-i)*(n-j)+n*n)/(n*n-i*j);
		}
	}
	printf("%.10lf",f[tx][ty]);
	return 0;
}
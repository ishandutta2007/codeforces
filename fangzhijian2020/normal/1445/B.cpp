#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||'9'<c)opt|=c=='-',c=getchar();
	while('0'<=c&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,a,b,c,d;
int main(){
	T=read()+1;
	while(--T){
		a=read();b=read();c=read();d=read();
		printf("%d\n",max(a+b,c+d));
	}
	return 0;
}
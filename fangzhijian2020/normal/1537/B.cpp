#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,m,x,y;
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();x=read();y=read();
//		if(dis(1,1,x,y)+dis(n,m,x,y)>dis(1,m,x,y)+dis(n,1,x,y)){
			printf("1 1 %d %d\n",n,m);
//		}
		
	}
	return 0;
}
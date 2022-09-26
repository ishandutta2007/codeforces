#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define N 200020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],c[N],vis[N];
inline int XOR(int i,int j){
	printf("XOR %d %d\n",i,j);
	fflush(stdout);
	return read();
}
inline int OR(int i,int j){
	printf("OR %d %d\n",i,j);
	fflush(stdout);
	return read();
}
inline int AND(int i,int j){
	printf("AND %d %d\n",i,j);
	fflush(stdout);
	return read();
}
void Output(){
	printf("!");
	for(int i=1;i<=n;++i){
		printf(" %d",a[i]);
	}
	printf("\n");
	fflush(stdout);
	exit(0);
}
void Solve_1(int x,int y){
	a[x]=a[y]=AND(x,y);
	if(x^1)a[1]=a[x]^c[x];
	for(int i=2;i<=n;++i){
		if(i==x||i==y)continue;
		a[i]=a[1]^c[i];
	}
	Output();
}
void Solve_2(int x,int y){
	a[1]=AND(1,x)|AND(1,y);
	for(int i=2;i<=n;++i){
		a[i]=a[1]^c[i];
	}
	Output();
}
int main(){
	n=read();
	for(int i=2;i<=n;++i){
		c[i]=XOR(1,i);
	}
	for(int i=2;i<=n;++i){
		if(!c[i]){
			Solve_1(1,i);
		}
		if(vis[c[i]]){
			Solve_1(vis[c[i]],i);
		}
		vis[c[i]]=i;
	}
	int x=0,y=0;
	for(int i=2;i<=n;++i){
		if(c[i]==1)x=i;
		if(c[i]==n-2)y=i;
	}
	Solve_2(x,y);
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 10010
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
int n,a[N],vis[N];
int Query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return read();
}
void Report(){
	printf("! ");
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
	fflush(stdout);
}
int main(){
	n=read();
	int las=1;
	for(int i=2;i<=n;++i){
		int A=Query(las,i);
		int B=Query(i,las);
		if(A>B){
			a[las]=A,las=i;
		}
		else{
			a[i]=B;
		}
	}
	for(int i=1;i<=n;++i){
		vis[a[i]]=1;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			a[las]=i;
			break;
		}
	}
	Report();
	return 0;
}
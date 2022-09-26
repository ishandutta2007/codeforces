#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 123
const int mx=100;
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
int n,m,cnt[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		++cnt[read()];
	}
	for(int i=100;i>=1;--i){
		int p=0;
		for(int j=1;j<=100;++j){
			p+=cnt[j]/i;
		}
		if(p>=n){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
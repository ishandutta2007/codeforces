#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int T;
int main(){
	T=read();
	while(T--){
		int x=read(),y=read(),z=read();
		if(x>y)swap(x,y);
		if(y>z)swap(y,z);
		if(x>y)swap(x,y);
		if(y^z){
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d %d %d\n",x,x,z);
	}
	return 0;
}
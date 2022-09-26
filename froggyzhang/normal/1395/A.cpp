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
int T,a,b,c,d;
bool check(int a,int b,int c,int d){
	return (a&1)+(b&1)+(c&1)+(d&1)<=1;
}
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
		if(check(a,b,c,d)){
			puts("Yes");
			continue;
		}
		if(a&&b&&c&&check(a-1,b-1,c-1,d+3)){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}
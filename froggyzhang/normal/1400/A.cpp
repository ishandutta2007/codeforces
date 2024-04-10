#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
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
int T,n;
char s[N];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;++i){
			putchar(s[(i<<1)-1]);
		}
		putchar('\n');
	}
	return 0;
}
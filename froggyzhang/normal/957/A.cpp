#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 123
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
int n;
char s[N];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<n;++i){
		if(s[i]^'?'&&s[i+1]^'?'&&s[i]==s[i+1]){
			return !printf("No\n");
		}
	}
	if(s[1]=='?'||s[n]=='?')return !printf("Yes\n");
	for(int i=2;i<n;++i){
		if(s[i]=='?'&&(s[i-1]=='?'||s[i+1]=='?'||s[i-1]==s[i+1])){
			return !printf("Yes\n");
		}
	}
	printf("No\n");
	return 0;
}
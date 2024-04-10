#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 100100
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
int n,a[N],b[N];
int st[N],top,now;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		st[++top]=i;
		while(now<a[i]){
			if(!top){
				puts("-1");
				return 0;
			}
			b[st[top--]]=now++;
		}
	}
	while(top)b[st[top--]]=1000000;
	for(int i=1;i<=n;++i){
		printf("%d ",b[i]);
	}
	return 0;
}